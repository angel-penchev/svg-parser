//
// Created by apenchev on 6/2/2022.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../../include/dom/DomElement.h"


class DomElementFixture : public ::testing::Test {
protected:
    const String fixtureDirectoryFilepath = PATH_TO_FIXTURES;
    const String domElementFilepath = fixtureDirectoryFilepath + "dom-element.xml";
    const String domElementWithChildrenFilepath = fixtureDirectoryFilepath + "dom-element-with-children.xml";

    DomElement *domElement{};

    void SetUp() override {
        // Open fixture file and construct DomElement
        std::ifstream file(domElementWithChildrenFilepath.getValue(), std::ios::in);
        ASSERT_TRUE(file);
        domElement = new DomElement(file);
        file.close();
    }

    void TearDown() override {
        // Delete allocated DomElement
        delete domElement;
    }
};

TEST_F(DomElementFixture, ShouldHandleFileInputWithNoChildren) {
    // Open fixture file and construct DomElement
    std::ifstream file(domElementFilepath.getValue(), std::ios::in);
    ASSERT_TRUE(file);
    DomElement domElementNoChildren = DomElement(file);
    file.close();

    // Validate tag value
    ASSERT_STREQ(domElementNoChildren.getTag().getValue(), "rect");

    // Validate attributes
    ASSERT_EQ(domElementNoChildren.getAttributes()[0], DomElementAttribute("x", "5"));
    ASSERT_EQ(domElementNoChildren.getAttributes()[1], DomElementAttribute("y", "5"));
    ASSERT_EQ(domElementNoChildren.getAttributes()[2], DomElementAttribute("width", "10"));
    ASSERT_EQ(domElementNoChildren.getAttributes()[3], DomElementAttribute("height", "10"));
    ASSERT_EQ(domElementNoChildren.getAttributes()[4], DomElementAttribute("fill", "green"));

    // Validate children vector is empty
    ASSERT_EQ(domElementNoChildren.getChildren().getSize(), 0);
}

TEST_F(DomElementFixture, ShouldHandleFileInputWithMultipleChildren) {

    // Validate tag value
    ASSERT_STREQ(domElement->getTag().getValue(), "svg");

    // Validate children count
    ASSERT_EQ(domElement->getChildren().getSize(), 3);

    // Child 0 validation
    ASSERT_STREQ(domElement->getChildren()[0]->getTag().getValue(), "rect");
    ASSERT_EQ(domElement->getChildren()[0]->getAttributes()[0], DomElementAttribute("x", "5"));
    ASSERT_EQ(domElement->getChildren()[0]->getAttributes()[1], DomElementAttribute("y", "5"));
    ASSERT_EQ(domElement->getChildren()[0]->getAttributes()[2], DomElementAttribute("width", "10"));
    ASSERT_EQ(domElement->getChildren()[0]->getAttributes()[3], DomElementAttribute("height", "10"));
    ASSERT_EQ(domElement->getChildren()[0]->getAttributes()[4], DomElementAttribute("fill", "green"));
    ASSERT_EQ(domElement->getChildren()[0]->getChildren().getSize(), 0);

    // Child 1 validation
    ASSERT_STREQ(domElement->getChildren()[1]->getTag().getValue(), "circle");
    ASSERT_EQ(domElement->getChildren()[1]->getAttributes()[0], DomElementAttribute("cx", "5"));
    ASSERT_EQ(domElement->getChildren()[1]->getAttributes()[1], DomElementAttribute("cy", "5"));
    ASSERT_EQ(domElement->getChildren()[1]->getAttributes()[2], DomElementAttribute("r", "10"));
    ASSERT_EQ(domElement->getChildren()[1]->getAttributes()[3], DomElementAttribute("fill", "blue"));
    ASSERT_EQ(domElement->getChildren()[1]->getChildren().getSize(), 0);

    // Child 2 validation
    ASSERT_STREQ(domElement->getChildren()[2]->getTag().getValue(), "rect");
    ASSERT_EQ(domElement->getChildren()[2]->getAttributes()[0], DomElementAttribute("x", "100"));
    ASSERT_EQ(domElement->getChildren()[2]->getAttributes()[1], DomElementAttribute("y", "60"));
    ASSERT_EQ(domElement->getChildren()[2]->getAttributes()[2], DomElementAttribute("width", "10"));
    ASSERT_EQ(domElement->getChildren()[2]->getAttributes()[3], DomElementAttribute("height", "10"));
    ASSERT_EQ(domElement->getChildren()[2]->getAttributes()[4], DomElementAttribute("fill", "red"));
    ASSERT_EQ(domElement->getChildren()[2]->getChildren().getSize(), 0);
}
