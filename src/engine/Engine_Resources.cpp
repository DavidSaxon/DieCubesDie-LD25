#include "Engine.hpp"

//FUNCTIONS
void Engine::loadTextures() {

    int width, height;
    bool hasAlpha;

	
    loadImage((char*) "resources/gfx/floor.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &floorTex);
    glBindTexture(GL_TEXTURE_2D, floorTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/floor1.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &floor1Tex);
    glBindTexture(GL_TEXTURE_2D, floor1Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/floor2.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &floor2Tex);
    glBindTexture(GL_TEXTURE_2D, floor2Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/floor3.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &floor3Tex);
    glBindTexture(GL_TEXTURE_2D, floor3Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/floor4.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &floor4Tex);
    glBindTexture(GL_TEXTURE_2D, floor4Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/redCube.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &redCubeTex);
    glBindTexture(GL_TEXTURE_2D, redCubeTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/redCube1.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &redCube1Tex);
    glBindTexture(GL_TEXTURE_2D, redCube1Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/redCube2.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &redCube2Tex);
    glBindTexture(GL_TEXTURE_2D, redCube2Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/redCube3.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &redCube3Tex);
    glBindTexture(GL_TEXTURE_2D, redCube3Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/redCube4.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &redCube4Tex);
    glBindTexture(GL_TEXTURE_2D, redCube4Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/blueCube.png", width, height, hasAlpha, &img);
    glGenTextures(1, &blueCubeTex);
    glBindTexture(GL_TEXTURE_2D, blueCubeTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/blueCube1.png", width, height, hasAlpha, &img);
    glGenTextures(1, &blueCube1Tex);
    glBindTexture(GL_TEXTURE_2D, blueCube1Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/blueCube2.png", width, height, hasAlpha, &img);
    glGenTextures(1, &blueCube2Tex);
    glBindTexture(GL_TEXTURE_2D, blueCube2Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/blueCube3.png", width, height, hasAlpha, &img);
    glGenTextures(1, &blueCube3Tex);
    glBindTexture(GL_TEXTURE_2D, blueCube3Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/blueCube4.png", width, height, hasAlpha, &img);
    glGenTextures(1, &blueCube4Tex);
    glBindTexture(GL_TEXTURE_2D, blueCube4Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/wall.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &wallTex);
    glBindTexture(GL_TEXTURE_2D, wallTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/wall1.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &wall1Tex);
    glBindTexture(GL_TEXTURE_2D, wall1Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

        loadImage((char*) "resources/gfx/wall2.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &wall2Tex);
    glBindTexture(GL_TEXTURE_2D, wall2Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

        loadImage((char*) "resources/gfx/wall3.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &wall3Tex);
    glBindTexture(GL_TEXTURE_2D, wall3Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

        loadImage((char*) "resources/gfx /wall4.png", width, height,
        hasAlpha, &img);
    glGenTextures(1, &wall4Tex);
    glBindTexture(GL_TEXTURE_2D, wall4Tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/spawn.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &spawnTex);
    glBindTexture(GL_TEXTURE_2D, spawnTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/exit.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &exitTex);
    glBindTexture(GL_TEXTURE_2D, exitTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/background.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &backTex);
    glBindTexture(GL_TEXTURE_2D, backTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/spikeBottomClean.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &spikeBottomCleanTex);
    glBindTexture(GL_TEXTURE_2D, spikeBottomCleanTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/spikeBottomBlood.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &spikeBottomBloodTex);
    glBindTexture(GL_TEXTURE_2D, spikeBottomBloodTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/spikeTopClean.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &spikeTopCleanTex);
    glBindTexture(GL_TEXTURE_2D, spikeTopCleanTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/spikeTopBlood.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &spikeTopBloodTex);
    glBindTexture(GL_TEXTURE_2D, spikeTopBloodTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/selection.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &selectionTex);
    glBindTexture(GL_TEXTURE_2D, selectionTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/remove.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &removeTex);
    glBindTexture(GL_TEXTURE_2D, removeTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/b1.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &b1);
    glBindTexture(GL_TEXTURE_2D, b1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/b2.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &b2);
    glBindTexture(GL_TEXTURE_2D, b2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/b3.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &b3);
    glBindTexture(GL_TEXTURE_2D, b3);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/b4.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &b4);
    glBindTexture(GL_TEXTURE_2D, b4);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/b5.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &b5);
    glBindTexture(GL_TEXTURE_2D, b5);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/b6.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &b6);
    glBindTexture(GL_TEXTURE_2D, b6);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/b7.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &b7);
    glBindTexture(GL_TEXTURE_2D, b7);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/b8.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &b8);
    glBindTexture(GL_TEXTURE_2D, b8);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/b9.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &b9);
    glBindTexture(GL_TEXTURE_2D, b9);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/b10.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &b10);
    glBindTexture(GL_TEXTURE_2D, b10);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/b11.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &b11);
    glBindTexture(GL_TEXTURE_2D, b11);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/b12.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &b12);
    glBindTexture(GL_TEXTURE_2D, b12);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/b13.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &b13);
    glBindTexture(GL_TEXTURE_2D, b13);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/rd1.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &rd1);
    glBindTexture(GL_TEXTURE_2D, rd1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/rd2.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &rd2);
    glBindTexture(GL_TEXTURE_2D, rd2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/rd3.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &rd3);
    glBindTexture(GL_TEXTURE_2D, rd3);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/rd4.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &rd4);
    glBindTexture(GL_TEXTURE_2D, rd4);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/bd1.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &bd1);
    glBindTexture(GL_TEXTURE_2D, bd1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/bd2.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &bd2);
    glBindTexture(GL_TEXTURE_2D, bd2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/bd3.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &bd3);
    glBindTexture(GL_TEXTURE_2D, bd3);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/bd4.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &bd4);
    glBindTexture(GL_TEXTURE_2D, bd4);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/d1.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &d1);
    glBindTexture(GL_TEXTURE_2D, d1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/d2.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &d2);
    glBindTexture(GL_TEXTURE_2D, d2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/d3.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &d3);
    glBindTexture(GL_TEXTURE_2D, d3);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/d4.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &d4);
    glBindTexture(GL_TEXTURE_2D, d4);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/d5.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &d5);
    glBindTexture(GL_TEXTURE_2D, d5);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/d6.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &d6);
    glBindTexture(GL_TEXTURE_2D, d6);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/d7.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &d7);
    glBindTexture(GL_TEXTURE_2D, d7);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/d8.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &d8);
    glBindTexture(GL_TEXTURE_2D, d8);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/d9.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &d9);
    glBindTexture(GL_TEXTURE_2D, d9);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/0.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &n0);
    glBindTexture(GL_TEXTURE_2D, n0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/1.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &n1);
    glBindTexture(GL_TEXTURE_2D, n1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/2.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &n2);
    glBindTexture(GL_TEXTURE_2D, n2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/3.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &n3);
    glBindTexture(GL_TEXTURE_2D, n3);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/4.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &n4);
    glBindTexture(GL_TEXTURE_2D, n4);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/5.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &n5);
    glBindTexture(GL_TEXTURE_2D, n5);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/6.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &n6);
    glBindTexture(GL_TEXTURE_2D, n6);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/7.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &n7);
    glBindTexture(GL_TEXTURE_2D, n7);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

        loadImage((char*) "resources/gfx/8.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &n8);
    glBindTexture(GL_TEXTURE_2D, n8);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/9.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &n9);
    glBindTexture(GL_TEXTURE_2D, n9);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/win.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &win);
    glBindTexture(GL_TEXTURE_2D, win);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    loadImage((char*) "resources/gfx/lose.png", width, height,
            hasAlpha, &img);
    glGenTextures(1, &lose);
    glBindTexture(GL_TEXTURE_2D, lose);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA,
        GL_UNSIGNED_BYTE, img);

    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}

/*Loads a png image*/
bool Engine::loadImage(char *name, int &outWidth, int &outHeight, bool &outHasAlpha, GLubyte **outData) {
    png_structp pngPtr;
    png_infop infoPtr;
    unsigned int sigRead = 0;
    int colorType, interlaceType;
    FILE *file;

    if ((file = fopen(name, "rb")) == NULL) return false;

    pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (pngPtr == NULL) {
        fclose(file);
        return false;
    }

    infoPtr = png_create_info_struct(pngPtr);
    if (infoPtr == NULL) {
        fclose(file);
        png_destroy_read_struct(&pngPtr, png_infopp_NULL, png_infopp_NULL);
        return false;
    }

    if (setjmp(png_jmpbuf(pngPtr))) {
        png_destroy_read_struct(&pngPtr, &infoPtr, png_infopp_NULL);
        fclose(file);
        return false;
    }

    png_init_io(pngPtr, file);
    png_set_sig_bytes(pngPtr, sigRead);

    png_read_png(pngPtr, infoPtr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, png_voidp_NULL);

    outWidth = infoPtr->width;
    outHeight = infoPtr->height;

    switch (infoPtr->color_type) {
        case PNG_COLOR_TYPE_RGBA:
            outHasAlpha = true;
            break;
        case PNG_COLOR_TYPE_RGB:
            outHasAlpha = false;
            break;
        default:
            cout << "Color type " << infoPtr->color_type << " not supported" << endl;
            png_destroy_read_struct(&pngPtr, &infoPtr, NULL);
            fclose(file);
            return false;
    }

    unsigned int rowBytes = png_get_rowbytes(pngPtr, infoPtr);
    *outData = (unsigned char*) malloc(rowBytes*outHeight);
    png_bytepp rowPointers = png_get_rows(pngPtr, infoPtr);

    for (int i = 0; i < outHeight; i++)
        memcpy(*outData+(rowBytes*(outHeight-1-i)), rowPointers[i], rowBytes);

    png_destroy_read_struct(&pngPtr, &infoPtr, png_infopp_NULL);
    fclose(file);

    return true;
}