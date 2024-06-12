#ifndef RESOURCES
#define RESOURCES

class Resources{
    protected:
        int id;
    public:
        /* Initialize a resource.
         * Should set an set an incremental id, so each Resrouce
         * have a unique identifier. */
        Resources();

        /* Get the unique id of a Resource */
        int getId();
};
#endif
