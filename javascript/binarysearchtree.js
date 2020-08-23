class Node {
    constructor(data, left = null, right = null) {
        this.data = data;
        this.left = left;
        this.right = right;
    }
}

class BST {
    constructor() {
        this.root = null;
    }

    add(data) {
        const node = this.root;
        if (node === null) {
            this.root = new Node(data);
            return true;
        } else {
            let searchTree = (node) => {
                if (data < node.data) {
                    if (node.left === null) {
                        node.left = new Node(data);
                        return true;
                    } else {
                        return searchTree(node.left);
                    }
                } else if (data > node.data) {
                    if (node.right === null) {
                        node.right = new Node(data);
                        return true;
                    } else {
                        return searchTree(node.right);
                    }
                } else {
                    return null;
                }
            }
            return searchTree(node);
        }
    }

    findMin() {
        let currNode = this.root;
        while (currNode.left !== null) {
            currNode = curNode.left;
        }
        return currNode.data;
    }

    findMax() {
        let currNode = this.root;
        while (currNode.right !== null) {
            curNode = curNode.right;
        }
        return curNode.data;
    }

    find(data) {
        let curNode = this.root;
        while (curNode.data !== data) {
            if (curNode.data < data) {
                curNode = curNode.left;
            } else if (curNode.data > data) {
                curNode = curNode.right;
            }
        }
        return curNode;
    }

    isPresent(data) {
        let currNode = this.root;
        while (currNode !== null) {
            if (data === currNode.data) {
                return true;
            } else if (data < currNode.data) {
                currNode = currNode.left;
            } else {
                currNode = currNode.right;
            }
        }
        return false;
    }

    remove(data) {
        const removeNode = (node, data) => {
            if (node === null) {
                return null;
            }
            if (node.data === data) {
                //has no child 
                if (node.left === null && node.right === null) {
                    return null;
                }
                //has right  child only.
                else if (node.left === null) {
                    return node.right;
                }
                //has left child only.
                else if (node.right === null) {
                    return node.left;
                }
                //has two child 
                let tempNode = node.right;
                while (tempNode.left !== null) { //finding leftmost child of right subtree of node to be removed.
                    tempNode = tempNode.left;
                }
                node.data = tempNode.data; //assigning data of leftmost child of right subtree of node to be removed , to node to be removed.
                node.right = removeNode(node.right, tempNode.data);
                return node;
            }
            else if (node.data > data) {
                node.left = removeNode(node.left, data);
                return node;
            }
            else if (node.data < data) {
                node.right = removeNode(node.right, data);
                return node;
            }
        }
        this.root = removeNode(this.root, data);
    }

    // The idea is to traverse the given Binary Tree. For every node, check if it is a leaf node.
    //  If yes, then return 1. If not leaf node then if the left subtree is NULL, then recur for the right subtree.
    //  And if the right subtree is NULL, then recur for the left subtree. If both left and right subtrees are not NULL, then take the minimum of two heights.
    // root node level is assumed to be 1.
    findMinHeight(node = this.root){
        if (node == null){
            return 0;
        }
        
        if (node.left == null && node.right == null){
            return 1;
        }

        if (node.left == null){
            return this.findMinHeight(node.right) + 1;
        }

        if (node.right == null){
            return this.findMinHeight(node.left) + 1;
        }
        return Math.min(this.findMinHeight(node.left),this.findMinHeight(node.right)) +1;
    }

    findMaxHeight(node = this.root){
        if (node == null){
            return 0;
        }
        
        if (node.left == null && node.right == null){
            return 1;
        }

        if (node.left == null){
            return this.findMaxHeight(node.right) + 1;
        }

        if (node.right == null){
            return this.findMaxHeight(node.left) + 1;
        }
        return Math.max(this.findMaxHeight(node.left),this.findMinHeight(node.right)) +1;
    }

    inOrder(){
        if (this.root == null){
            return null;
        }else {
            let result = [];
            let traverseInOrder = (node) =>{
                if(node.left != null){
                    traverseInOrder(node.left);
                }
                result.push(node.data);
                if (node.right != null){
                    traverseInOrder(node.right);
                }
                return result;
            }
            return traverseInOrder(this.root);
        }
        
    }
    
    preOrder(){
        if (this.root == null){
            return null;
        }else {
            let result = [];
            let traversePreOrder = (node) =>{
                result.push(node.data);
                if(node.left != null){
                    traversePreOrder(node.left);
                }
                if (node.right != null){
                    traversePreOrder(node.right);
                }
                return result;
            }
            return traversePreOrder(this.root);
        }       
    };
    
    postOrder(){
        if (this.root == null){
            return null;
        }else {
            let result = [];
            let traversePostOrder = (node) =>{
                if(node.left != null){
                    traversePostOrder(node.left);
                }
                if (node.right != null){
                    traversePostOrder(node.right);
                }
                result.push(node.data);
                return result;
            }
            return traversePostOrder(this.root);
        }       
    };

    levelOrder(){
        if (this.root == null){
            return null;
        }else {
            let result = [];
            let Q = [];
            Q.push(this.root);
            while(Q.length > 0){
                let node  = Q.shift();
                result.push(node.data);
                if(node.left != null){
                    Q.push(node.left);
                }
                if(node.right != null){
                    Q.push(node.right);
                }
            }
            return result;
        }
    };

    depthOrder () {
        if (this.root == null){
            return null;
        }else {
            let result = []
            let S = [];
            S.push(this.root);
            while (S.length>0){
                let node = S.pop();
                result.push(node.data);
                if(node.right != null){
                    S.push(node.right);
                }
                if(node.left != null){
                    S.push(node.left);
                }
            }
            return result;
        }
    };
}




let bst = new BST();
bst.add(50);
bst.add(17);
bst.add(12);
bst.add(9)
bst.add(14);
bst.add(23);
bst.add(19);
bst.add(72);
bst.add(54);
bst.add(67);
bst.add(76);

console.log(bst.inOrder());
console.log(bst.preOrder());
console.log(bst.postOrder());
console.log(bst.levelOrder());
console.log(bst.depthOrder());
console.log(bst.findMaxHeight());

// console.log(bst.isPresent(50));
// bst.remove(76);
// console.log(76,bst.isPresent(76));

// bst.remove(54);
// console.log(54,bst.isPresent(54));
// console.log(67,bst.isPresent(67));

// bst.remove(17);
// console.log(23,bst.isPresent(23));
// console.log(19,bst.isPresent(19));
// console.log(12,bst.isPresent(12));
