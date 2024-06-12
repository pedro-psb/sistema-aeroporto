#ifndef RESOURCE
#define RESOURCE

class Resource{
    protected:
        int id;
        
    public:
        Resource();
        Resource(int id);
        int getId();
        void setId(int id);
};
#endif