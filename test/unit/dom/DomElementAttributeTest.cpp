//
// Created by apenchev on 6/2/2022.
//

#include <gtest/gtest.h>
#include "../../../include/helper/String.h"
#include "../../../include/dom/DomElementAttribute.h"

class DomElementAttributeFixture : public ::testing::Test {
protected:
    const String fixtureDirectoryFilepath = PATH_TO_FIXTURES;
    const String domAttributeFilepath = fixtureDirectoryFilepath + "dom-attribute.xml";

    DomElementAttribute *domAttribute{};

    void SetUp() override {
        // Open fixture file and construct DomElementAttribute
        std::ifstream file(domAttributeFilepath.getValue(), std::ios::in);
        ASSERT_TRUE(file);
        domAttribute = new DomElementAttribute(file);
        file.close();
    }

    void TearDown() override {
        delete domAttribute;
    }
};

TEST_F(DomElementAttributeFixture, ShouldExposeAFileInputConstructor) {
    // Validate attribute name
    ASSERT_STREQ(domAttribute->getName().getValue(), "width");

    // Validate attribute value
    ASSERT_STREQ(domAttribute->getValue().getValue(), "10");
}
