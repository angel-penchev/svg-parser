//
// Created by apenchev on 6/20/2022.
//

#include <gtest/gtest.h>
#include "../../../include/helper/String.h"
#include "../../../include/dom/DomDocument.h"

class DomDocumentFixture : public ::testing::Test {
protected:
    const String fixtureDirectoryFilepath = PATH_TO_FIXTURES;
    const String domDocumentFilepath = fixtureDirectoryFilepath + "dom-document.xml";

    DomDocument *domDocument{};

    void SetUp() override {
        // Open fixture file and construct DomDocument
        domDocument = new DomDocument(domDocumentFilepath);
    }

    void TearDown() override {
        delete domDocument;
    }
};

TEST_F(DomDocumentFixture, ShouldExposeAFilepathConstructor) {
    // Validate filename
    ASSERT_STREQ(domDocument->getFilename().getValue(), domDocumentFilepath.getValue());

    // Validate parent node
    // Validate tag value
    ASSERT_STREQ(domDocument->getParentElement()->getTag().getValue(), "svg");

    // Validate children count
    ASSERT_EQ(domDocument->getParentElement()->getChildren().getSize(), 3);
}
