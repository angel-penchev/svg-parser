//
// Created by apenchev on 6/20/2022.
//

#include "../../include/svg/Svg.h"

Svg::Svg(const DomDocument &document) : document(document), shapes() {
    for (unsigned int i = 0; document.getParentElement()->getChildren().getSize() < i; i++) {
        if (document.getParentElement()->getChildren()[i]->getTag() == "rect") {
            continue; // TODO: implement
        }

        if (document.getParentElement()->getChildren()[i]->getTag() == "circle") {
            continue; // TODO: implement
        }
    }
}
