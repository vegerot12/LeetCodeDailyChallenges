// O(n2 * ackerman) ~ O(n2) As for every edge we do every eother edge
// O(m+n) - wheree m is edge info and n is no of nodes in union find  

class DSU
{
public:
    vector<int> parent;
    vector<int> size;
    int components;

    DSU(int n)
    {
        parent.resize(n + 1, -1); // node strts from 1 to n so n+1
        size.resize(n + 1, 1);
        components = n;
    }

    int findParent(int x)
    {

        if (parent[x] == -1)
            return x;
        return parent[x] = findParent(parent[x]);
    }

    bool unionEdge(int x, int y)
    {
        int px = findParent(x);
        int py = findParent(y);

        if (px == py)
            return false; // union not happend alrd connected so false

        if (size[px] > size[py])
        {
            parent[py] = px; // x is big so it should be parent
            size[px] += size[py];
        }
        else
        {
            parent[px] = py;
            size[py] += size[px];
        }

        components--; // we performed union and linked two nodes so disconnected comp cnt decreased
        return true;  // union happened so true
    }

    bool isConnected()
    {
        return components == 1;
    }
};

class Solution
{
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {

        // change the incoming edges 2D vector to include the index
        for (int i = 0; i < edges.size(); i++)
        {
            edges[i].push_back(i);
        }
        // Now edges will have v1,v2, w, original_index
        // sort based on weight
        sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int> &b)
             { return a[2] < b[2]; });

        // find the MST
        DSU dsu(n);
        int mst_weight = 0;
        for (auto &e : edges)
        {
            if (dsu.unionEdge(e[0], e[1])) // if union success add the weight of edge
                mst_weight += e[2];
        }

        // Now we find critical edges by stopping each of the edges and trying to find mst and check new weight
        vector<int> critical, pseudo;

        for (auto &e : edges)
        {
            DSU dsu1(n);
            int new_mst = 0;
            // try other mst without that edge
            for (auto &ne : edges)
            {
                if (e[3] != ne[3])
                { // if not same index

                    if (dsu1.unionEdge(ne[0], ne[1]))
                    { // if union success add the weight of edge
                        new_mst += ne[2];
                    }
                }
            }

            // if mst not formed or if new wei more than mst weight and the edge that was excluded now is a critical edge
            if (!dsu1.isConnected() || mst_weight < new_mst)
            {
                critical.push_back(e[3]);
                continue; // a critcal edge can never be a pseudocrical edge so we continue here
            }

            // to find pesudocritical edge (edge found in some mst) we force each edge and try to form many mst and if new mst == mst weight then it is pesudo

            DSU dsu2(n);

            // try other mst by forcing that edge
            dsu2.unionEdge(e[0], e[1]);
            new_mst = e[2];
            for (auto &ne : edges)
            {

                if (dsu2.unionEdge(ne[0], ne[1]))
                {
                    new_mst += ne[2];
                } // if union success add the weight of edge
            }

            if (new_mst == mst_weight)
                pseudo.push_back(e[3]);
        }

        return {critical, pseudo};
    }
};