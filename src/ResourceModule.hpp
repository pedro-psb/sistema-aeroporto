#include "Common.hpp"
#include "Resource.hpp"

class ResourceModule {
public:
  /* Try to allocate a Resource of @ResourceType for a given @dateTime
   * Raises "ResourceNotAvailableError" if its not available at that time */
  Resource allocateResource(ResourceType resourceType, DateTime datime);

  /* Free the @resource for usage on the time it was being used. */
  void freeResource(Resource resource);
};
