#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include <memory>
#include "../src/Player.hpp"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

class PlayerTest : public testing::Test {
    protected:
        void SetUp() override {
            player_ = std::make_unique<Player>(Player());
        }

        std::unique_ptr<Player> player_;
};

// Check that simple parts of Player (setters, getters etc.), and those it inherited work correctly
TEST_F(PlayerTest, SimplePlayerAssertions) {

    EXPECT_EQ(player_->getName(), "Player");
    player_->setName("Test");
    EXPECT_EQ(player_->getName(), "Test");
    player_->setName("Laura");
    EXPECT_EQ(player_->getName(), "Laura");
    player_->setName("12nuc239SA(*8r)");
    EXPECT_EQ(player_->getName(), "12nuc239SA(*8r)");
}
