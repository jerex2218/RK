#include "Computer.h"
#include "ConcreteComputers.h"
#include <gtest/gtest.h>

TEST(LaptopTest, PriceTest) {
    Laptop laptop;
    testing::internal::CaptureStdout();
    laptop.price();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "4000$\n");
}

TEST(LaptopTest, DescriptionTest) {
    Laptop laptop;
    testing::internal::CaptureStdout();
    laptop.description();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Laptops are mobile, portable and multimedia\n");
}

TEST(DesktopTest, PriceTest) {
    Desktop desktop;
    testing::internal::CaptureStdout();
    desktop.price();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "5000$\n");
}

TEST(DesktopTest, DescriptionTest) {
    Desktop desktop;
    testing::internal::CaptureStdout();
    desktop.description();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Desktops are fixed\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
