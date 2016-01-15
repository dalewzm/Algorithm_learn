using namespace std;
typedef struct Node
{
    Node()
    {
        key = 0;
        pre = NULL;
        next = NULL;
    }
    int key;
    Node* pre;
    Node* next;
}Node;


class LRUCache
{
public:
    LRUCache(int capacity)
    {
        sz = 0;
        cap = capacity;
        head.next = NULL;
        end.next = NULL;
    }
    ~LRUCache()
    {
        Node* tmp = head.next;
        Node* d;
        while (tmp)
        {
            d = tmp;
            tmp = tmp->next;
            delete d;
        }
    }
    void changePos(int key)
    {
        Node* tmp = head.next;
        Node* oldhead = tmp;
        if(tmp && tmp->key == key)
            return;
        while (tmp)
        {
            if (tmp->key == key)
                break;
            tmp = tmp->next;
        }

        if (tmp->pre && tmp->next)
        {
            Node *p = tmp->pre;
            p->next = tmp->next;
            tmp->next->pre = p;
        }
        else if (tmp->pre)
        {
            end.next = tmp->pre;
            tmp->pre->next =NULL;
            tmp->pre = NULL;
        }
        else{
            ;
        }
        head.next = tmp;
        if(tmp!=oldhead)
        {
            tmp->next = oldhead;
            oldhead->pre = tmp;
        }
    }

    void insertHead(int key)
    {
        Node* tmp = head.next;
        Node* newnode = new Node;
        newnode->key = key;
        head.next = newnode;
        if (end.next == NULL)
            end.next = newnode;
        if (tmp){
            newnode->next = tmp;
            tmp->pre = newnode;
        }
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;
        changePos(key);
        return cache[key];
    }
    void set(int key, int value)
    {
        if (cache.find(key) == cache.end())
        {
            insertHead(key);
            if (sz < cap)
            {
                sz++;
            }
            else{

                Node *tmp = end.next;
                end.next = tmp->pre;
                cache.erase(tmp->key);
                if (tmp->pre)
                    tmp->pre->next = NULL;
                delete tmp;
            }

        }
        else
        {
            changePos(key);

        }
        cache[key] = value;
    }
    int cap;
    int sz;
    Node head, end;
    unordered_map<int, int> cache;
};
