//
// Created by apenchev on 6/2/2022.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../../include/dom/DomElement.h"


class DomElementFixture : public ::testing::Test {
protected:
    const String fixtureDirectoryFilepath = PATH_TO_FIXTURES;
    const String domSingleElementFilepath = fixtureDirectoryFilepath + "dom-single-element.xml";

    DomElement *domElement{};

    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(DomElementFixture, ShouldHandleFileInputWithNoChildren) {
    // Open fixture file and construct DomElement
    std::ifstream file(domSingleElementFilepath.getValue(), std::ios::in);
    ASSERT_TRUE(file);
    DomElement domElementFromFile = DomElement(file);
    file.close();

    // Validate tag value
    ASSERT_STREQ(domElementFromFile.getTag().getValue(), "rect");

    // Validate attributes
    ASSERT_STREQ(domElementFromFile.getAttributes()[0].getName().getValue(), "x");
    ASSERT_STREQ(domElementFromFile.getAttributes()[0].getValue().getValue(), "5");

    ASSERT_STREQ(domElementFromFile.getAttributes()[1].getName().getValue(), "y");
    ASSERT_STREQ(domElementFromFile.getAttributes()[1].getValue().getValue(), "5");

    ASSERT_STREQ(domElementFromFile.getAttributes()[2].getName().getValue(), "width");
    ASSERT_STREQ(domElementFromFile.getAttributes()[2].getValue().getValue(), "10");

    ASSERT_STREQ(domElementFromFile.getAttributes()[3].getName().getValue(), "height");
    ASSERT_STREQ(domElementFromFile.getAttributes()[3].getValue().getValue(), "10");

    ASSERT_STREQ(domElementFromFile.getAttributes()[4].getName().getValue(), "fill");
    ASSERT_STREQ(domElementFromFile.getAttributes()[4].getValue().getValue(), "green");

    // Validate children vector is empty
    ASSERT_EQ(domElementFromFile.getChildren().getSize(), 0);
}
