class Node {
public:
	int key, val;
	Node* next;
	Node* prev;
    
	Node() {
		key = val = -1;
		next = prev = NULL;
	}

	Node(int k, int value) {
		key = k;
		val = value;
		next = prev = NULL;
	}
};


class LRUCache {
private:

  unordered_map <int, Node*> mpp; // Map data structure
	int cap; // Capacity
	Node* head; // Dummy head pointer
	Node* tail; // Dummy tail pointer
	void deleteNode(Node* node) {

		// Get the previous and next pointers
		Node* prevNode = node-> prev;
		Node* nextNode = node-> next;

		// Remove pointers to node
		prevNode-> next = nextNode;
		nextNode-> prev = prevNode;
	}

	void insertAfterHead(Node* node) {

		Node* nextNode = head-> next;
		head-> next = node;
		nextNode-> prev = node;
		node-> prev = head;
		node-> next = nextNode;
	}

public:
	LRUCache(int capacity) {
		cap = capacity; // Set the capacity
		mpp.clear(); // Clear the cache
		head = new Node();
		tail = new Node();
		head-> next = tail;
		tail-> prev = head;
	}

	int get(int key_) {
		if(mpp.find(key_) == mpp.end())
			return -1;

		Node* node = mpp[key_]; // Get the node
		int val = node->val; // Get the value

		// Delete the node
		deleteNode(node);
		insertAfterHead(node);

		// Return the stored value
		return val;
	}

	void put(int key_, int value) {

		if(mpp.find(key_) != mpp.end()) {
		    
			Node* node = mpp[key_]; // Get the node
			node->val = value; 
			deleteNode(node);
			insertAfterHead(node);
			
			return;
		}

		if(mpp.size() == cap) {
			Node* node = tail->prev;
			mpp.erase(node-> key);
			deleteNode(node);
		}

		Node* newNode = new Node(key_, value);
		mpp[key_] = newNode;
		insertAfterHead(newNode);
	}
};


int main() {
	// LRU Cache
	LRUCache cache(2);

	// Queries
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << " ";
	cache.put(3, 3);
	cout << cache.get(2) << " ";
	cache.put(4, 4);
	cout << cache.get(1) << " ";
	cout << cache.get(3) << " ";
	cout << cache.get(4) << " ";

	return 0;
}
