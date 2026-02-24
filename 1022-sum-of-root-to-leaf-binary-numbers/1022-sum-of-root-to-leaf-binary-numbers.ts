/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function sumRootToLeaf(root: TreeNode | null): number {
    return DFS(root, 0);
};

function DFS(rt : TreeNode, x : number) : number{
    if (rt == null)
        return 0;
    x = x * 2 + rt.val;
    if (rt.left == rt.right)
        return x;
    return DFS(rt.left, x) + DFS(rt.right, x);
}