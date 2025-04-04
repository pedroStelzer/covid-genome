#ifndef QUEUE_H
#define QUEUE_H

template <typename T> class Queue
{
    private:

        Node<T> *frontNode;
        Node<T> *backNode;
        int size;

    public:

        Queue() : frontNode(nullptr), backNode(nullptr), size(0) {}

        void enqueue(T value) 
        {   
            Node<T> *newNode = new Node<T>(value);
            if(empty())
            {
                frontNode = backNode = newNode;
            }
            else
            {
                backNode->next = newNode;
                backNode = newNode;
            }
            size++;
        }

        void dequeue() 
        {
            if(!empty())
            {
                Node<T> *temp = frontNode;
                frontNode = frontNode->next;
                delete temp;

                if(frontNode == nullptr)
                {
                    backNode == nullptr;
                }

                size--;
            }
        }

        T front() 
        {
            if(!empty())
            {
                return frontNode->data;
            }
        }

        bool empty() 
        {
            return frontNode == nullptr;
        }

        int lenght() 
        {
            return size;
        }

};

#endif // QUEUE_H