//
// Created by sneakyfox on 10/14/20.
//

#include "ObjLoader.h"
#include "../../exceptions/ResourceException.h"

#include <fstream>
#include <sstream>

namespace XiTechRegistration {
    ResourceLoaderRegistration<ObjLoader> _objLoader("obj");
}

void ObjLoader::load(const std::string &filePath, Resource* resource) {

    std::ifstream objFile(filePath);

    if(!objFile.is_open()) {
        throw ResourceException("Could not open file " + filePath);
    }

    auto positions = std::vector<Vector3<float>*>();
    auto normals = std::vector<Vector3<float>*>();
    auto uvs = std::vector<Vector2<float>*>();

    auto vertices = std::vector<Vertex>();
    auto vertexDefinitions = std::map<std::string, unsigned int>();
    auto elementIndices = std::vector<unsigned int>();

    std::string line;

    auto createVertex = [&vertices, &positions, &normals, &uvs, &vertexDefinitions, &elementIndices](std::string &vertexDefinition, unsigned int &elementIndex) {

        std::istringstream istream(vertexDefinition);
        unsigned int posIndex, normalIndex, uvIndex;
        char separator;
        istream >> posIndex >> separator >> uvIndex >> separator >> normalIndex;

        auto seenVertex = vertexDefinitions.find(vertexDefinition);

        if(seenVertex != vertexDefinitions.end()) {

            elementIndices.push_back(seenVertex->second);

        } else {

            vertices.emplace_back(
                    positions.at(posIndex - 1),
                    normals.at(normalIndex - 1),
                    uvs.at(uvIndex - 1)
            );

            elementIndices.push_back(elementIndex);
            vertexDefinitions[vertexDefinition] = elementIndex;

            elementIndex++;

        }

    };

    unsigned int elementIndex = 0;

    while(std::getline(objFile, line)) {

        auto lineStart = line.substr(0, 2);
        auto lineData = line.substr(2);

        std::istringstream sStream(lineData);

        if(lineStart == "v ") {
            float x, y, z;
            sStream >> x >> y >> z;
            positions.emplace_back(new Vector3<float>(x, y, z));
        } else if(lineStart == "vt") {
            float u, v;
            sStream >> u >> v;
            uvs.emplace_back(new Vector2<float>(u, v));
        } else if(lineStart == "vn") {
            float x, y, z;
            sStream >> x >> y >> z;
            normals.emplace_back(new Vector3<float>(x, y, z));
        } else if(lineStart == "f ") {
            std::string face1, face2, face3;
            sStream >> face1 >> face2 >> face3;
            createVertex(face1, elementIndex);
            createVertex(face2, elementIndex);
            createVertex(face3, elementIndex);
        }

    }

    auto* model = (Model*) resource;
    auto meshes = std::vector<Mesh*>{new Mesh(vertices, elementIndices)};
    model->setMeshes(meshes);

}
