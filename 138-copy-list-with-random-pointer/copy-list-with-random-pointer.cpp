class Solution {
public:
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);

            temp->next = copy;
            copy->next = nextElement;

            temp = nextElement;
        }
    }

    void connectRandomPointers(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = temp->next;
            if (temp->random) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head) {
        Node* dummyNode = new Node(-1);
        Node* copyTail = dummyNode;
        Node* temp = head;

        while (temp != NULL) {
            Node* copyNode = temp->next;
            Node* nextOriginal = copyNode->next;

            // Detach copy node
            copyTail->next = copyNode;
            copyTail = copyNode;

            // Restore original list
            temp->next = nextOriginal;

            temp = nextOriginal;
        }

        return dummyNode->next;
    }

    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};
