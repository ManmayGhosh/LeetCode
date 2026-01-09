class Solution(object):
    def subtreeWithAllDeepest(self, root):
        parent = {}
        depth = {}
        self.maxDepth = 0

        def dfs(node, par, d):
            if not node:
                return
            parent[node] = par
            depth[node] = d
            self.maxDepth = max(self.maxDepth, d)
            dfs(node.left, node, d + 1)
            dfs(node.right, node, d + 1)

        dfs(root, None, 0)

        deepest = [n for n in depth if depth[n] == self.maxDepth]

        curr = set(deepest)
        while len(curr) > 1:
            nxt = set()
            for node in curr:
                nxt.add(parent[node])
            curr = nxt

        return next(iter(curr))