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
    const String domSingleElementWithChildrenFilepath =
            fixtureDirectoryFilepath + "dom-single-element-with-children.xml";

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
    ASSERT_EQ(domElementFromFile.getAttributes()[0], DomElementAttribute("x", "5"));
    ASSERT_EQ(domElementFromFile.getAttributes()[1], DomElementAttribute("y", "5"));
    ASSERT_EQ(domElementFromFile.getAttributes()[2], DomElementAttribute("width", "10"));
    ASSERT_EQ(domElementFromFile.getAttributes()[3], DomElementAttribute("height", "10"));
    ASSERT_EQ(domElementFromFile.getAttributes()[4], DomElementAttribute("fill", "green"));

    // Validate children vector is empty
    ASSERT_EQ(domElementFromFile.getChildren().getSize(), 0);
}

TEST_F(DomElementFixture, ShouldHandleFileInputWithMultipleChildren) {
    // Open fixture file and construct DomElement
    std::ifstream file(domSingleElementWithChildrenFilepath.getValue(), std::ios::in);
    ASSERT_TRUE(file);
    DomElement domElementFromFile = DomElement(file);
    file.close();

    // Validate tag value
    ASSERT_STREQ(domElementFromFile.getTag().getValue(), "svg");

    // Validate children count
    ASSERT_EQ(domElementFromFile.getChildren().getSize(), 3);

    // Child 0 validation
    ASSERT_STREQ(domElementFromFile.getChildren()[0]->getTag().getValue(), "rect");
    ASSERT_EQ(domElementFromFile.getChildren()[0]->getAttributes()[0], DomElementAttribute("x", "5"));
    ASSERT_EQ(domElementFromFile.getChildren()[0]->getAttributes()[1], DomElementAttribute("y", "5"));
    ASSERT_EQ(domElementFromFile.getChildren()[0]->getAttributes()[2], DomElementAttribute("width", "10"));
    ASSERT_EQ(domElementFromFile.getChildren()[0]->getAttributes()[3], DomElementAttribute("height", "10"));
    ASSERT_EQ(domElementFromFile.getChildren()[0]->getAttributes()[4], DomElementAttribute("fill", "green"));
    ASSERT_EQ(domElementFromFile.getChildren()[0]->getChildren().getSize(), 0);

    // Child 1 validation
    ASSERT_STREQ(domElementFromFile.getChildren()[1]->getTag().getValue(), "circle");
    ASSERT_EQ(domElementFromFile.getChildren()[1]->getAttributes()[0], DomElementAttribute("cx", "5"));
    ASSERT_EQ(domElementFromFile.getChildren()[1]->getAttributes()[1], DomElementAttribute("cy", "5"));
    ASSERT_EQ(domElementFromFile.getChildren()[1]->getAttributes()[2], DomElementAttribute("r", "10"));
    ASSERT_EQ(domElementFromFile.getChildren()[1]->getAttributes()[3], DomElementAttribute("fill", "blue"));
    ASSERT_EQ(domElementFromFile.getChildren()[1]->getChildren().getSize(), 0);

    // Child 2 validation
    ASSERT_STREQ(domElementFromFile.getChildren()[2]->getTag().getValue(), "rect");
    ASSERT_EQ(domElementFromFile.getChildren()[2]->getAttributes()[0], DomElementAttribute("x", "100"));
    ASSERT_EQ(domElementFromFile.getChildren()[2]->getAttributes()[1], DomElementAttribute("y", "60"));
    ASSERT_EQ(domElementFromFile.getChildren()[2]->getAttributes()[2], DomElementAttribute("width", "10"));
    ASSERT_EQ(domElementFromFile.getChildren()[2]->getAttributes()[3], DomElementAttribute("height", "10"));
    ASSERT_EQ(domElementFromFile.getChildren()[2]->getAttributes()[4], DomElementAttribute("fill", "red"));
    ASSERT_EQ(domElementFromFile.getChildren()[2]->getChildren().getSize(), 0);
}
