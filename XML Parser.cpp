#include <iostream>
#include <vector>
#include "pugixml.hpp"

struct Sprite {
    std::string name;
    int x, y, width, height;
};

int main() {
    // XML 파일을 읽어들입니다.
    pugi::xml_document doc;
    if (!doc.load_file("simpledata.xml")) {
        std::cerr << "XML 파일을 읽어들이지 못했습니다." << std::endl;
        return 1;
    }

    // TextureAtlas 엘리먼트를 찾습니다.
    pugi::xml_node atlasNode = doc.child("TextureAtlas");

    // Sprite 벡터를 생성합니다.
    std::vector<Sprite> sprites;

    // 각 sprite 엘리먼트를 순회하면서 정보를 추출합니다.
    for (pugi::xml_node spriteNode = atlasNode.child("sprite"); spriteNode; spriteNode = spriteNode.next_sibling("sprite")) {
        Sprite sprite;
        sprite.name = spriteNode.attribute("n").value();
        sprite.x = spriteNode.attribute("x").as_int();
        sprite.y = spriteNode.attribute("y").as_int();
        sprite.width = spriteNode.attribute("w").as_int();
        sprite.height = spriteNode.attribute("h").as_int();
        sprites.push_back(sprite);
    }

    // 추출한 Sprite 정보를 출력합니다.
    for (const Sprite& sprite : sprites) {
        std::cout << "Name: " << sprite.name << std::endl;
        std::cout << "X: " << sprite.x << ", Y: " << sprite.y << std::endl;
        std::cout << "Width: " << sprite.width << ", Height: " << sprite.height << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
