#ifndef RESOURCE
#define RESOURCE

class Resource{
    protected:
        int resource_id;

    private:
        static int currentResourceId;
        
    public:
        Resource();
        int getResourceId();
        void setResourceId(int id);
};
#endif