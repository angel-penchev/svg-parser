//
// Created by apenchev on 6/2/2022.
//

#include <gtest/gtest.h>
#include "../../../include/helper/String.h"
#include "../../../include/dom/DomElementAttribute.h"

class DomElementAttributeFixture : public ::testing::Test {
protected:
    const String fixtureDirectoryFilepath = PATH_TO_FIXTURES;
    const String domSingleAttributeFilepath = fixtureDirectoryFilepath + "dom-single-attribute.xml";

    DomElementAttribute *domElementAttribute{};

    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(DomElementAttributeFixture, ShouldExposeAFileInputConstructor) {
    // Construct DomElementAttribute from file
    std::ifstream file(domSingleAttributeFilepath.getValue(), std::ios::in);
    ASSERT_TRUE(file);
    DomElementAttribute domAttributeFromFile = DomElementAttribute(file);
    file.close();

    // Validate attribute name
    ASSERT_STREQ(domAttributeFromFile.getName().getValue(), "width");

    // Validate attribute value
    ASSERT_STREQ(domAttributeFromFile.getValue().getValue(), "10");
}