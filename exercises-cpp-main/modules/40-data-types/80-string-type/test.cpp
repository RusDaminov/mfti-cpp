#include "test_helper.h"

TEST_CASE("testing solution") {
  std::string expected = "11\n";
  std::string actual = get_output(sizeof(expected), "code-basics");

  CHECK(actual == expected);
}
