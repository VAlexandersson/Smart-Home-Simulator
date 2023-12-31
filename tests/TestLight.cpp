#include "gtest/gtest.h"
#include "../include/Light.h"


class LightTest : public ::testing::Test {
protected:
    Light light;
};

TEST_F(LightTest, TurnsOn) {
light.turnOn();
ASSERT_TRUE(light.getState());
}

TEST_F(LightTest, TurnsOff) {
light.turnOff();
ASSERT_FALSE(light.getState());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

