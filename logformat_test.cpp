#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "logformat.hpp"

using namespace logformat;

struct test_t {
	std::string to_string() const {
		return std::string("test_t");
	}
};

struct test_no_member_t {};
std::string to_string(test_no_member_t v) {
	return std::string("test_no_member_t");
}

TEST_CASE( "string conversion tests", "[param_to_string]" ) {
	REQUIRE( param_to_string(1.0f) == std::string("1.000000") );
	REQUIRE( param_to_string("string") == std::string("string") );

	REQUIRE( param_to_string(test_t()) == std::string("test_t") );

	REQUIRE( param_to_string(test_no_member_t()) == std::string("test_no_member_t") );

}

// vim: syntax=cpp11:sts=4:ts=4:sw=4:noet
