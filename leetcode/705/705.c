struct BST {
    int val;
    struct BST *left;
    struct BST *right;
};
typedef struct BST BSTree;

BSTree* BSTreeCreate(int val) {
    BSTree *tree = malloc(sizeof(BSTree));
    if (tree) {
        tree->val = val;
        tree->left = NULL;
        tree->right = NULL;
    }
    return tree;
}

int successor(BSTree *node) {
    node = node->right;
    while (node->left) {
        node = node->left;
    }
    return node->val;
}

int predecessor(BSTree *node) {
    node = node->left;
    while (node->right) {
        node = node->right;
    }
    return node->val;
}

BSTree *deleteNode(BSTree *root, int key) {
    if (!root)
        return NULL;

    if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else {
        if (!root->left && !root->right) {
            free(root);
            root = NULL;
        } else if (root->right) {
            root->val = successor(root);
            root->right = deleteNode(root->right, root->val);
        } else if (root->left) {
            root->val = predecessor(root);
            root->left = deleteNode(root->left, root->val);
        }
    }
    return root;
}

bool search(BSTree *root, int val) {
    if (!root)
        return false;

    while (root) {
        if (val > root->val) {
            root = root->right;
        } else if (val < root->val) {
            root = root->left;
        } else {
            return true;
        }
    }
    return false;
}

void insert(BSTree *root, int val) {
    while (root) {
        if (val > root->val) {
            if (root->right) {
                root = root->right;
            } else {
                root->right = BSTreeCreate(val);
                break;
            }
        } else if (val < root->val) {
            if (root->left) {
                root = root->left;
            } else {
                root->left = BSTreeCreate(val);
                break;
            }
        } else {
            break;
        }
    }
}

typedef struct {
    BSTree *root;
} BSTreeFacade;

static bool FacadeSearch(BSTreeFacade *facade, int val) {
    return (facade->root) ? search(facade->root, val) : false;
}


static void FacadeInsert(BSTreeFacade *facade, int val) {
    if (!facade->root)
        facade->root = BSTreeCreate(val);
    else
        insert(facade->root, val);
}

static void FacadeRemove(BSTreeFacade *facade, int val) {
    if (facade->root)
        facade->root = deleteNode(facade->root, val);
}

BSTreeFacade* BSTreeFacadeCreate() {
    BSTreeFacade *facade = malloc(sizeof(BSTreeFacade));
    if (facade)
        facade->root = NULL;
    return facade;
}

#define BUCKET_BITS (10)
#define GOLDEN_RATIO_32 0x61C88647

static int hash_32(unsigned int key) {
    return key * GOLDEN_RATIO_32 >> (32 - BUCKET_BITS);
    /* return key % (1 << BUCKET_BITS); */
}

typedef struct {
    BSTreeFacade* buckets[1 << BUCKET_BITS];
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet *s = malloc(sizeof(MyHashSet));
    memset(s, 0, sizeof(MyHashSet));
    return s;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int bkey = hash_32(key);
    if (!obj->buckets[bkey])
        obj->buckets[bkey] = BSTreeFacadeCreate();

    FacadeInsert(obj->buckets[bkey], key);
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int bkey = hash_32(key);

    if (obj->buckets[bkey]) {
        FacadeRemove(obj->buckets[bkey], key);
    }
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int bkey = hash_32(key);

    if (!obj->buckets[bkey])
        return false;

    return FacadeSearch(obj->buckets[bkey], key);
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}



/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
