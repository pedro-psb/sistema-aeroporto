#ifndef RESOURCE
#define RESOURCE

class Resource{
    protected:
        int id;

    private:
        static int currentId;
        
    public:
        Resource();
        int getId();
        void setId(int id);
};
#endif