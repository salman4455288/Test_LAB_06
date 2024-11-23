#include<iostream>
#include "pch.h"
#include "C:\Users\Shah Salman\Desktop\data structures lab\LAB__06\LAB__06\Q1.h"
#include "C:\Users\Shah Salman\Desktop\data structures lab\LAB__06\LAB__06\Q2.h"

using namespace std;

// Question 1
TEST(Dynamic_List, addend) {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    DynamicList obj1(a, 5);
    obj1.addEnd(8);
    EXPECT_EQ(8, obj1.arr[5]);
    obj1.print();
    obj1.addEnd(9);
    EXPECT_EQ(9, obj1.arr[6]);
    obj1.print();
}
TEST(Dynamic_List, addstart) {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    DynamicList obj1(a, 5);
    obj1.addStart(6);
    EXPECT_EQ(6, obj1.arr[0]);
    for (int i = 1; i < 6; i++) {
        EXPECT_EQ(i, obj1.arr[i]);
    }
    obj1.print();

}
TEST(Dynamic_List, addGivenPosition) {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    DynamicList obj1(a, 5);
    obj1.addGivenP(7, 3);
    EXPECT_EQ(7, obj1.arr[3]);
    obj1.print();
    obj1.addGivenP(9, 3);
    EXPECT_EQ(9, obj1.arr[3]);
    obj1.print();
}
TEST(Dynamic_List, deleteStart) {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    DynamicList obj1(a, 5);
    obj1.delStart();
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(i + 2, obj1.arr[i]);
    }
    obj1.print();

}
TEST(Dynamic_List, deleteEnd) {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    DynamicList obj1(a, 5);
    obj1.delEnd();
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(i + 1, obj1.arr[i]);
    }
    obj1.print();

}
TEST(Dynamic_List, deleteGivenPosition) {
    int* a = new int[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    DynamicList obj1(a, 5);
    obj1.delGivenP(2);
    EXPECT_EQ(4, obj1.arr[2]);
    obj1.print();
}
TEST(Dynamic_List, case1) {
    int* a = new int[7];
    for (int i = 0; i < 7; i++) {
        a[i] = i + 1;
    }
    DynamicList obj1(a, 7);
    EXPECT_EQ(5, obj1.Next(3));
    EXPECT_EQ(3, obj1.Previous(3));
    EXPECT_EQ(0, obj1.checkDupli());
}
//---------------------------------------------------
// Question 2


TEST(SafeArrayTest, WithinBounds) {
    safeArray list(2, 13);
    safeArray yourList(-5, 9);

    list[2] = 10;
    EXPECT_EQ(list[2], 10);

    yourList[-5] = 20;
    EXPECT_EQ(yourList[-5], 20);
}

TEST(SafeArrayTest, OutOfBounds)
{
    // We capture the output to check the error message
    testing::internal::CaptureStderr();
    /*use EXPECT_EXIT to capture the program's standard error (stderr) output when certain conditions are met.
     You want to ensure that attempting to access out-of-bounds elements triggers an error message and exits the program. */

    EXPECT_EXIT(
        {
            safeArray list(2, 13);
            std::cout << list[1] << std::endl;
        },
        ::testing::ExitedWithCode(1),
        "Error: Index out of bounds"
    );
    std::string stderr_output = testing::internal::GetCapturedStderr();
    EXPECT_FALSE(stderr_output.empty()); // Ensure there is some error message

    testing::internal::CaptureStderr();
    EXPECT_EXIT(
        {
            safeArray yourList(-5, 9);
            std::cout << yourList[10] << std::endl;
        },
        ::testing::ExitedWithCode(1),
        "Error: Index out of bounds"
    );
    stderr_output = testing::internal::GetCapturedStderr();
    EXPECT_FALSE(stderr_output.empty()); // Ensure there is some error message
}

