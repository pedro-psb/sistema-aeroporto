#include "../lib/catch.hpp"
#include "../src/ResourceModule.hpp"

TEST_CASE("Given a fresh ResourceModule", "[functional]") {
  ResourceModule resourceMod = ResourceModule();

  SECTION("When allocate a Resource that is available at a DateTime."){};
  SECTION("When allocate a Resource that is not available at a DateTime."){};
  SECTION("When free a Resource."){};
}
