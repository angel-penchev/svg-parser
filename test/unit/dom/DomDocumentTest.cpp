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
    const String outDomDocumentFilepath = "out-dom-document.xml";

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
    // Validate xml version tag
    ASSERT_STREQ(domDocument->getVersionTag().getValue(), "<?xml version=\"1.0\" standalone=\"no\"?>");

    // Validate doctype tag
    ASSERT_STREQ(
            domDocument->getDoctypeTag().getValue(),
            "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">");

    // Validate tag value
    ASSERT_STREQ(domDocument->getParentElement()->getTag().getValue(), "svg");

    // Validate attributes count
    ASSERT_EQ(domDocument->getParentElement()->getAttributes().getSize(), 0);

    // Validate children count
    ASSERT_EQ(domDocument->getParentElement()->getChildren().getSize(), 3);
}

TEST_F(DomDocumentFixture, ShouldExposeAMethodForSaving) {
    // Save the DomDocument
    domDocument->setFilename(outDomDocumentFilepath);
    domDocument->save();

    // Verify file contents
    std::ifstream resultFile(outDomDocumentFilepath.getValue(), std::ios::in);
    ASSERT_TRUE(resultFile);
    DomDocument domDocumentFromFile(outDomDocumentFilepath);
}
