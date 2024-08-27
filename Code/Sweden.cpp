#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <sstream>
#include <ctime>
#include <Windows.h>
#include <iostream>

int main();
int IntructionSw();
int ViborKostSw();
int ViborStavkaSw(int sumkost);
int gameSw(int stavka_number, int summkost);
int ResultSw(int summkost, int stavka_number);

int MenuSw()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), L"Ben", sf::Style::Close);
    window.setFramerateLimit(144);

    sf::Music sound;
    if (!sound.openFromFile("Audio\\click.mp3"))
    {
        return 1;
    }

    sf::Font FontArimoSemiBold;
    if (!FontArimoSemiBold.loadFromFile("Font\\Arimo-SemiBold.ttf"))
    {
        return 1;
    }

    sf::Font FontCalibril;
    if (!FontCalibril.loadFromFile("Font\\calibril.ttf"))
    {
        return 1;
    }

    sf::Font FontExplanatory;
    if (!FontExplanatory.loadFromFile("Font\\PTF75F.ttf")) {
        return 1;
    }

    sf::Texture TextureBack;
    if (!TextureBack.loadFromFile("Texture\\images.jpg"))
    {
        return 1;
    }

    sf::Texture TextureGame;
    if (!TextureGame.loadFromFile("Texture\\Game.png"))
    {
        return 1;
    }

    sf::Texture AnimationClick;
    if (!AnimationClick.loadFromFile("Texture\\AnimationClick.png"))
    {
        return 1;
    }

    sf::Texture TextureInstruction;
    if (!TextureInstruction.loadFromFile("Texture\\Instruction.png"))
    {
        return 1;
    }

    sf::Texture TextureLanguage;
    if (!TextureLanguage.loadFromFile("Texture\\Language.png"))
    {
        return 1;
    }

    sf::Texture TextureExit;
    if (!TextureExit.loadFromFile("Texture\\Exit.png"))
    {
        return 1;
    }

    sf::Image icon;
    if (!icon.loadFromFile("Icons\\icons.png"))
    {
        return 1;
    }

    sf::Image cursorImage;
    if (!cursorImage.loadFromFile("Icons\\cursor.png"))
    {
        return 1;
    }

    sf::Vector2u clickSpot(15, 6);
    sf::Cursor cursor;
    if (!cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), clickSpot))
    {
        return 1;
    }

    sf::Sprite SpriteBack;
    sf::Vector2u textureSize = TextureBack.getSize();
    sf::Vector2u windowSize = window.getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    SpriteBack.setTexture(TextureBack);
    SpriteBack.setScale(scaleX, scaleY);

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Sprite SpriteGame;
    SpriteGame.setTexture(TextureGame);
    SpriteGame.setScale(00.3, 00.2);
    SpriteGame.setPosition(750, 250);

    sf::Sprite SpriteInstruction;
    SpriteInstruction.setTexture(TextureInstruction);
    SpriteInstruction.setScale(00.3, 00.2);
    SpriteInstruction.setPosition(750, 450);

    sf::Sprite SpriteLanguage;
    SpriteLanguage.setTexture(TextureLanguage);
    SpriteLanguage.setScale(00.3, 00.2);
    SpriteLanguage.setPosition(750, 650);

    sf::Sprite SpriteExit;
    SpriteExit.setTexture(TextureExit);
    SpriteExit.setScale(00.3, 00.2);
    SpriteExit.setPosition(750, 850);

    sf::Text TextHeading;
    TextHeading.setFont(FontArimoSemiBold);
    TextHeading.setString(L"   Tärningsspel\nHuvudmeny");
    TextHeading.setCharacterSize(75.6);
    TextHeading.setFillColor(sf::Color::White);
    TextHeading.setPosition(680, 30);

    sf::Text TextGame;
    TextGame.setFont(FontCalibril);
    TextGame.setString(L"Starta spelet");
    TextGame.setCharacterSize(45);
    TextGame.setFillColor(sf::Color::Black);
    TextGame.setPosition(790, 280);

    sf::Text TextInstruction;
    TextInstruction.setFont(FontCalibril);
    TextInstruction.setString(L"Instruktion");
    TextInstruction.setCharacterSize(45);
    TextInstruction.setFillColor(sf::Color::Black);
    TextInstruction.setPosition(825, 485);

    sf::Text TextLanguage;
    TextLanguage.setFont(FontCalibril);
    TextLanguage.setString(L"Val av spelspråk");
    TextLanguage.setCharacterSize(45);
    TextLanguage.setFillColor(sf::Color::Black);
    TextLanguage.setPosition(775, 685);

    sf::Text TextExit;
    TextExit.setFont(FontCalibril);
    TextExit.setString(L"Lämnar spelet");
    TextExit.setCharacterSize(45);
    TextExit.setFillColor(sf::Color::Black);
    TextExit.setPosition(820, 885);

    sf::Text TextAvtor;
    TextAvtor.setFont(FontExplanatory);
    TextAvtor.setString(L"Författare: Aleksey_Shulzhenko\n     Instagram: @Tlgtms");
    TextAvtor.setCharacterSize(45);
    TextAvtor.setFillColor(sf::Color::White);
    TextAvtor.setPosition(30, 950);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(SpriteBack);
        window.draw(SpriteGame);
        window.draw(SpriteInstruction);
        window.draw(SpriteLanguage);
        window.draw(SpriteExit);
        window.draw(TextHeading);
        window.draw(TextGame);
        window.draw(TextInstruction);
        window.draw(TextLanguage);
        window.draw(TextExit);
        window.draw(TextAvtor);
        window.setMouseCursor(cursor);

        sf::Vector2i MousePozition = sf::Mouse::getPosition(window);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteGame.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.3, 00.2);
                SpriteAnimationClick.setPosition(750, 250);
                window.draw(SpriteAnimationClick);
                window.draw(TextGame);
                window.display();
                Sleep(500);
                window.close();
                ViborKostSw();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteInstruction.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.3, 00.2);
                SpriteAnimationClick.setPosition(750, 450);
                window.draw(SpriteAnimationClick);
                window.draw(TextInstruction);
                window.display();
                Sleep(500);
                window.close();
                IntructionSw();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteLanguage.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.3, 00.2);
                SpriteAnimationClick.setPosition(750, 650);
                window.draw(SpriteAnimationClick);
                window.draw(TextLanguage);
                window.display();
                Sleep(500);
                window.close();
                main();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteExit.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.3, 00.2);
                SpriteAnimationClick.setPosition(750, 850);
                window.draw(SpriteAnimationClick);
                window.draw(TextExit);
                window.display();
                Sleep(500);
                window.close();
            }
        }
        window.display();
    }
    return 0;
}

int IntructionSw()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), L"Ben", sf::Style::Close);
    window.setFramerateLimit(144);

    sf::Music sound;
    if (!sound.openFromFile("Audio\\click.mp3"))
    {
        return 1;
    }

    sf::Texture TextureBack;
    if (!TextureBack.loadFromFile("Texture\\images.jpg"))
    {
        return 1;
    }

    sf::Image cursorImage;
    if (!cursorImage.loadFromFile("Icons\\cursor.png"))
    {
        return 1;
    }

    sf::Image icon;
    if (!icon.loadFromFile("Icons\\icons.png"))
    {
        return 1;
    }

    sf::Font FontArimoSemiBold;
    if (!FontArimoSemiBold.loadFromFile("Font\\Arimo-SemiBold.ttf"))
    {
        return 1;
    }

    sf::Font FontExplanatory;
    if (!FontExplanatory.loadFromFile("Font\\PTF75F.ttf"))
    {
        return 1;
    }

    sf::Font FontCalibril;
    if (!FontCalibril.loadFromFile("Font\\calibril.ttf"))
    {
        return 1;
    }

    sf::Texture WindowInstruction;
    if (!WindowInstruction.loadFromFile("Texture\\WindowInstruction.png"))
    {
        return 1;
    }

    sf::Texture AnimationClick;
    if (!AnimationClick.loadFromFile("Texture\\AnimationClick.png"))
    {
        return 1;
    }

    sf::Texture TextureGame;
    if (!TextureGame.loadFromFile("Texture\\Game.png"))
    {
        return 1;
    }

    sf::Texture TextureInstruction;
    if (!TextureInstruction.loadFromFile("Texture\\Instruction.png"))
    {
        return 1;
    }

    sf::Texture TextureLanguage;
    if (!TextureLanguage.loadFromFile("Texture\\Language.png"))
    {
        return 1;
    }

    sf::Texture TextureExit;
    if (!TextureExit.loadFromFile("Texture\\Exit.png"))
    {
        return 1;
    }

    sf::Vector2u clickSpot(15, 6);
    sf::Cursor cursor;
    if (!cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), clickSpot))
    {
        return 1;
    }

    sf::Sprite SpriteBack;
    sf::Vector2u textureSize = TextureBack.getSize();
    sf::Vector2u windowSize = window.getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    SpriteBack.setTexture(TextureBack);
    SpriteBack.setScale(scaleX, scaleY);

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Sprite SpriteInstruction;
    SpriteInstruction.setTexture(WindowInstruction);
    SpriteInstruction.setScale(1.25, 0.9);
    SpriteInstruction.setPosition(260, 150);

    sf::Sprite SpriteGame;
    SpriteGame.setTexture(TextureGame);
    SpriteGame.setScale(00.3, 00.2);
    SpriteGame.setPosition(1500, 840);

    sf::Sprite SpriteLanguage;
    SpriteLanguage.setTexture(TextureLanguage);
    SpriteLanguage.setScale(00.3, 00.2);
    SpriteLanguage.setPosition(540, 840);

    sf::Sprite SpriteMenu;
    SpriteMenu.setTexture(TextureInstruction);
    SpriteMenu.setScale(00.3, 00.2);
    SpriteMenu.setPosition(1040, 840);

    sf::Sprite SpriteExit;
    SpriteExit.setTexture(TextureExit);
    SpriteExit.setScale(00.3, 00.2);
    SpriteExit.setPosition(80, 840);

    sf::Text TextHeading;
    TextHeading.setFont(FontArimoSemiBold);
    TextHeading.setString(L"Instruktion");
    TextHeading.setCharacterSize(75.6);
    TextHeading.setFillColor(sf::Color::White);
    TextHeading.setPosition(757, 30);

    sf::Text TextInstruction;
    TextInstruction.setFont(FontExplanatory);
    TextInstruction.setString(L"Dice-spelet är ett spel som simulerar två tärningar i intervallet från 1\ntill 6 (upp till 12 totalt). Till exempel: Om summan av de sjunkna siffrorna är mindre än 7 och spelaren gissade ett nummer mindre än 7, vinner han den gjorda insatsen Om summan av siffrorna som faller är större än 7 och spelaren gissade ett nummer större än 7 vinner han också\nden gjorda insatsen. Om spelaren gissade summan av siffrorna, får han fyra gånger fler poäng än vad som gjorts. Insatsen är förlorad om det inte finns någon av de beskrivna situationerna. Vid \nstartögonblicket har spelaren 100 poäng.");
    TextInstruction.setCharacterSize(45);
    TextInstruction.setFillColor(sf::Color::White);
    TextInstruction.setPosition(290, 180);

    sf::Text TextGame;
    TextGame.setFont(FontCalibril);
    TextGame.setString(L"Starta spelet");
    TextGame.setCharacterSize(45);
    TextGame.setFillColor(sf::Color::White);
    TextGame.setPosition(1540, 875);

    sf::Text TextExit;
    TextExit.setFont(FontCalibril);
    TextExit.setString(L"Avsluta spelet");
    TextExit.setCharacterSize(45);
    TextExit.setFillColor(sf::Color::White);
    TextExit.setPosition(140, 875);

    sf::Text TextLanguage;
    TextLanguage.setFont(FontCalibril);
    TextLanguage.setString(L"Språkval");
    TextLanguage.setCharacterSize(45);
    TextLanguage.setFillColor(sf::Color::White);
    TextLanguage.setPosition(610, 875);

    sf::Text TextMenu;
    TextMenu.setFont(FontCalibril);
    TextMenu.setString(L"Återgå till menyn");
    TextMenu.setCharacterSize(30);
    TextMenu.setFillColor(sf::Color::White);
    TextMenu.setPosition(1070, 885);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(SpriteBack);
        window.draw(TextHeading);
        window.draw(SpriteInstruction);
        window.draw(TextInstruction);
        window.draw(SpriteGame);
        window.draw(SpriteExit);
        window.draw(TextGame);
        window.draw(TextExit);
        window.draw(SpriteLanguage);
        window.draw(TextLanguage);
        window.draw(SpriteMenu);
        window.draw(TextMenu);
        window.setMouseCursor(cursor);

        sf::Vector2i MousePozition = sf::Mouse::getPosition(window);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteGame.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.3, 00.2);
                SpriteAnimationClick.setPosition(1500, 840);
                window.draw(SpriteAnimationClick);
                window.draw(TextGame);
                window.display();
                Sleep(500);
                window.close();
                ViborKostSw();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteLanguage.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.3, 00.2);
                SpriteAnimationClick.setPosition(540, 840);
                window.draw(SpriteAnimationClick);
                window.draw(TextLanguage);
                window.display();
                Sleep(500);
                window.close();
                main();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteExit.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.3, 00.2);
                SpriteAnimationClick.setPosition(80, 840);
                window.draw(SpriteAnimationClick);
                window.draw(TextExit);
                window.display();
                Sleep(500);
                window.close();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteMenu.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.3, 00.2);
                SpriteAnimationClick.setPosition(1040, 840);
                window.draw(SpriteAnimationClick);
                window.draw(TextMenu);
                window.display();
                Sleep(500);
                window.close();
                MenuSw();
            }
        }

        window.display();
    }
    return 0;
}

int ViborKostSw()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), L"Ben", sf::Style::Close);
    window.setFramerateLimit(144);

    sf::Music sound;
    if (!sound.openFromFile("Audio\\click.mp3"))
    {
        return 1;
    }

    sf::Texture TextureBack;
    if (!TextureBack.loadFromFile("Texture\\images.jpg"))
    {
        return 1;
    }

    sf::Texture TextureNumber;
    if (!TextureNumber.loadFromFile("Texture\\Number.png"))
    {
        return 1;
    }

    sf::Image cursorImage;
    if (!cursorImage.loadFromFile("Icons\\cursor.png"))
    {
        return 1;
    }

    sf::Image icon;
    if (!icon.loadFromFile("Icons\\icons.png"))
    {
        return 1;
    }

    sf::Texture WindowInstruction;
    if (!WindowInstruction.loadFromFile("Texture\\WindowInstruction.png"))
    {
        return 1;
    }

    sf::Font FontArimoSemiBold;
    if (!FontArimoSemiBold.loadFromFile("Font\\Arimo-SemiBold.ttf"))
    {
        return 1;
    }

    sf::Font FontExplanatory;
    if (!FontExplanatory.loadFromFile("Font\\PTF75F.ttf"))
    {
        return 1;
    }

    sf::Font FontCalibril;
    if (!FontCalibril.loadFromFile("Font\\calibril.ttf"))
    {
        return 1;
    }

    sf::Texture AnimationClick;
    if (!AnimationClick.loadFromFile("Texture\\AnimationClick.png"))
    {
        return 1;
    }

    sf::Texture TextureGame;
    if (!TextureGame.loadFromFile("Texture\\Game.png"))
    {
        return 1;
    }

    sf::Texture TextureInstruction;
    if (!TextureInstruction.loadFromFile("Texture\\Instruction.png"))
    {
        return 1;
    }

    sf::Texture TextureLanguage;
    if (!TextureLanguage.loadFromFile("Texture\\Language.png"))
    {
        return 1;
    }

    sf::Texture TextureExit;
    if (!TextureExit.loadFromFile("Texture\\Exit.png"))
    {
        return 1;
    }

    sf::Vector2u clickSpot(15, 6);
    sf::Cursor cursor;
    if (!cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), clickSpot))
    {
        return 1;
    }

    sf::Sprite SpriteBack;
    sf::Vector2u textureSize = TextureBack.getSize();
    sf::Vector2u windowSize = window.getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    SpriteBack.setTexture(TextureBack);
    SpriteBack.setScale(scaleX, scaleY);

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Sprite SpriteNumber2;
    SpriteNumber2.setTexture(TextureNumber);
    SpriteNumber2.setScale(00.2, 00.2);
    SpriteNumber2.setPosition(70, 170);

    sf::Sprite SpriteNumber3;
    SpriteNumber3.setTexture(TextureNumber);
    SpriteNumber3.setScale(00.2, 00.2);
    SpriteNumber3.setPosition(460, 170);

    sf::Sprite SpriteNumber4;
    SpriteNumber4.setTexture(TextureNumber);
    SpriteNumber4.setScale(00.2, 00.2);
    SpriteNumber4.setPosition(850, 170);

    sf::Sprite SpriteNumber5;
    SpriteNumber5.setTexture(TextureNumber);
    SpriteNumber5.setScale(00.2, 00.2);
    SpriteNumber5.setPosition(1230, 170);

    sf::Sprite SpriteNumber6;
    SpriteNumber6.setTexture(TextureNumber);
    SpriteNumber6.setScale(00.2, 00.2);
    SpriteNumber6.setPosition(1620, 170);

    sf::Sprite SpriteNumber7;
    SpriteNumber7.setTexture(TextureNumber);
    SpriteNumber7.setScale(00.2, 00.2);
    SpriteNumber7.setPosition(70, 360);

    sf::Sprite SpriteNumber8;
    SpriteNumber8.setTexture(TextureNumber);
    SpriteNumber8.setScale(00.2, 00.2);
    SpriteNumber8.setPosition(460, 360);

    sf::Sprite SpriteNumber9;
    SpriteNumber9.setTexture(TextureNumber);
    SpriteNumber9.setScale(00.2, 00.2);
    SpriteNumber9.setPosition(850, 360);

    sf::Sprite SpriteNumber10;
    SpriteNumber10.setTexture(TextureNumber);
    SpriteNumber10.setScale(00.2, 00.2);
    SpriteNumber10.setPosition(1230, 360);

    sf::Sprite SpriteNumber11;
    SpriteNumber11.setTexture(TextureNumber);
    SpriteNumber11.setScale(00.2, 00.2);
    SpriteNumber11.setPosition(1620, 360);

    sf::Sprite SpriteExit;
    SpriteExit.setTexture(TextureExit);
    SpriteExit.setScale(00.2, 00.2);
    SpriteExit.setPosition(70, 550);

    sf::Sprite SpriteGame;
    SpriteGame.setTexture(TextureGame);
    SpriteGame.setScale(00.2, 00.2);
    SpriteGame.setPosition(460, 550);

    sf::Sprite SpriteNumber12;
    SpriteNumber12.setTexture(TextureNumber);
    SpriteNumber12.setScale(00.2, 00.2);
    SpriteNumber12.setPosition(850, 550);

    sf::Sprite SpriteMenu;
    SpriteMenu.setTexture(TextureInstruction);
    SpriteMenu.setScale(00.2, 00.2);
    SpriteMenu.setPosition(1230, 550);

    sf::Sprite SpriteLanguage;
    SpriteLanguage.setTexture(TextureLanguage);
    SpriteLanguage.setScale(00.2, 00.2);
    SpriteLanguage.setPosition(1620, 550);

    sf::Sprite SpriteInstruction;
    SpriteInstruction.setTexture(WindowInstruction);
    SpriteInstruction.setScale(1.52, 0.3);
    SpriteInstruction.setPosition(80, 760);

    sf::Text TextHeading;
    TextHeading.setFont(FontArimoSemiBold);
    TextHeading.setString(L"Val av tärningssumma");
    TextHeading.setCharacterSize(75.6);
    TextHeading.setFillColor(sf::Color::White);
    TextHeading.setPosition(620, 30);

    sf::Text TextNumber2;
    TextNumber2.setFont(FontArimoSemiBold);
    TextNumber2.setString(L"2");
    TextNumber2.setCharacterSize(80);
    TextNumber2.setFillColor(sf::Color::White);
    TextNumber2.setPosition(165, 180);

    sf::Text TextNumber3;
    TextNumber3.setFont(FontArimoSemiBold);
    TextNumber3.setString(L"3");
    TextNumber3.setCharacterSize(80);
    TextNumber3.setFillColor(sf::Color::White);
    TextNumber3.setPosition(555, 180);

    sf::Text TextNumber4;
    TextNumber4.setFont(FontArimoSemiBold);
    TextNumber4.setString(L"4");
    TextNumber4.setCharacterSize(80);
    TextNumber4.setFillColor(sf::Color::White);
    TextNumber4.setPosition(945, 180);

    sf::Text TextNumber5;
    TextNumber5.setFont(FontArimoSemiBold);
    TextNumber5.setString(L"5");
    TextNumber5.setCharacterSize(80);
    TextNumber5.setFillColor(sf::Color::White);
    TextNumber5.setPosition(1325, 180);

    sf::Text TextNumber6;
    TextNumber6.setFont(FontArimoSemiBold);
    TextNumber6.setString(L"6");
    TextNumber6.setCharacterSize(80);
    TextNumber6.setFillColor(sf::Color::White);
    TextNumber6.setPosition(1715, 180);

    sf::Text TextNumber7;
    TextNumber7.setFont(FontArimoSemiBold);
    TextNumber7.setString(L"7");
    TextNumber7.setCharacterSize(80);
    TextNumber7.setFillColor(sf::Color::White);
    TextNumber7.setPosition(165, 370);

    sf::Text TextNumber8;
    TextNumber8.setFont(FontArimoSemiBold);
    TextNumber8.setString(L"8");
    TextNumber8.setCharacterSize(80);
    TextNumber8.setFillColor(sf::Color::White);
    TextNumber8.setPosition(555, 370);

    sf::Text TextNumber9;
    TextNumber9.setFont(FontArimoSemiBold);
    TextNumber9.setString(L"9");
    TextNumber9.setCharacterSize(80);
    TextNumber9.setFillColor(sf::Color::White);
    TextNumber9.setPosition(945, 370);

    sf::Text TextNumber10;
    TextNumber10.setFont(FontArimoSemiBold);
    TextNumber10.setString(L"10");
    TextNumber10.setCharacterSize(80);
    TextNumber10.setFillColor(sf::Color::White);
    TextNumber10.setPosition(1300, 370);

    sf::Text TextNumber11;
    TextNumber11.setFont(FontArimoSemiBold);
    TextNumber11.setString(L"11");
    TextNumber11.setCharacterSize(80);
    TextNumber11.setFillColor(sf::Color::White);
    TextNumber11.setPosition(1690, 370);

    sf::Text TextNumber12;
    TextNumber12.setFont(FontArimoSemiBold);
    TextNumber12.setString(L"12");
    TextNumber12.setCharacterSize(80);
    TextNumber12.setFillColor(sf::Color::White);
    TextNumber12.setPosition(920, 560);

    sf::Text TextExit;
    TextExit.setFont(FontCalibril);
    TextExit.setString(L"Avsluta spelet");
    TextExit.setCharacterSize(45);
    TextExit.setFillColor(sf::Color::White);
    TextExit.setPosition(75, 580);

    sf::Text TextGame;
    TextGame.setFont(FontCalibril);
    TextGame.setString(L"Start\n       spelet\n   nytt");
    TextGame.setCharacterSize(35);
    TextGame.setFillColor(sf::Color::White);
    TextGame.setPosition(500, 550);

    sf::Text TextMenu;
    TextMenu.setFont(FontCalibril);
    TextMenu.setString(L"Återvända\n          till\n       meny");
    TextMenu.setCharacterSize(35);
    TextMenu.setFillColor(sf::Color::White);
    TextMenu.setPosition(1250, 550);

    sf::Text TextLanguage;
    TextLanguage.setFont(FontCalibril);
    TextLanguage.setString(L"Välja\n   den andra\n   språk");
    TextLanguage.setCharacterSize(35);
    TextLanguage.setFillColor(sf::Color::White);
    TextLanguage.setPosition(1680, 550);

    sf::Text TextExplanatory;
    TextExplanatory.setFont(FontCalibril);
    TextExplanatory.setString(L"                      Välj summan av tärningarna, för vidare spel.\n(För att välja summan av tärningarna måste du klicka på fältet med ett nummer.)");
    TextExplanatory.setCharacterSize(60);
    TextExplanatory.setFillColor(sf::Color::White);
    TextExplanatory.setPosition(120, 780);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(SpriteBack);
        window.draw(SpriteNumber2);
        window.draw(SpriteNumber3);
        window.draw(SpriteNumber4);
        window.draw(SpriteNumber5);
        window.draw(SpriteNumber6);
        window.draw(SpriteNumber7);
        window.draw(SpriteNumber8);
        window.draw(SpriteNumber9);
        window.draw(SpriteNumber10);
        window.draw(SpriteNumber11);
        window.draw(SpriteNumber12);
        window.draw(SpriteInstruction);
        window.draw(SpriteExit);
        window.draw(SpriteGame);
        window.draw(SpriteMenu);
        window.draw(SpriteLanguage);
        window.draw(TextNumber2);
        window.draw(TextNumber3);
        window.draw(TextNumber4);
        window.draw(TextNumber5);
        window.draw(TextNumber6);
        window.draw(TextNumber7);
        window.draw(TextNumber8);
        window.draw(TextNumber9);
        window.draw(TextNumber10);
        window.draw(TextNumber11);
        window.draw(TextNumber12);
        window.draw(TextHeading);
        window.draw(TextExplanatory);
        window.draw(TextExit);
        window.draw(TextGame);
        window.draw(TextMenu);
        window.draw(TextLanguage);
        window.setMouseCursor(cursor);

        sf::Vector2i MousePozition = sf::Mouse::getPosition(window);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber2.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(70, 170);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber2);
                int sumkost = 2;
                window.display();
                Sleep(500);
                window.close();
                ViborStavkaSw(sumkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber3.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(460, 170);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber3);
                int sumkost = 3;
                window.display();
                Sleep(500);
                window.close();
                ViborStavkaSw(sumkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber4.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(850, 170);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber4);
                int sumkost = 4;
                window.display();
                Sleep(500);
                window.close();
                ViborStavkaSw(sumkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber5.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(1230, 170);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber5);
                int sumkost = 5;
                window.display();
                Sleep(500);
                window.close();
                ViborStavkaSw(sumkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber6.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(1620, 170);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber6);
                int sumkost = 6;
                window.display();
                Sleep(500);
                window.close();
                ViborStavkaSw(sumkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber7.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(70, 360);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber7);
                int sumkost = 7;
                window.display();
                Sleep(500);
                window.close();
                ViborStavkaSw(sumkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber8.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(460, 360);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber8);
                int sumkost = 8;
                window.display();
                Sleep(500);
                window.close();
                ViborStavkaSw(sumkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber9.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(850, 360);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber9);
                int sumkost = 9;
                window.display();
                Sleep(500);
                window.close();
                ViborStavkaSw(sumkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber10.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(1230, 360);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber10);
                int sumkost = 10;
                window.display();
                Sleep(500);
                window.close();
                ViborStavkaSw(sumkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber11.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(1620, 360);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber11);
                int sumkost = 11;
                window.display();
                Sleep(500);
                window.close();
                ViborStavkaSw(sumkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber12.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(850, 550);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber12);
                int sumkost = 12;
                window.display();
                Sleep(500);
                window.close();
                ViborStavkaSw(sumkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteGame.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(460, 550);
                window.draw(SpriteAnimationClick);
                window.draw(TextGame);
                window.display();
                Sleep(500);
                window.close();
                ViborKostSw();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteExit.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(70, 550);
                window.draw(SpriteAnimationClick);
                window.draw(TextExit);
                window.display();
                Sleep(500);
                window.close();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteMenu.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(1230, 550);
                window.draw(SpriteAnimationClick);
                window.draw(TextMenu);
                window.display();
                Sleep(500);
                window.close();
                MenuSw();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteLanguage.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(1620, 550);
                window.draw(SpriteAnimationClick);
                window.draw(TextLanguage);
                window.display();
                Sleep(500);
                window.close();
                main();
            }
        }
        window.display();
    }
    return 0;
}

int ViborStavkaSw(int sumkost)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), L"Ben", sf::Style::Close);
    window.setFramerateLimit(144);

    sf::Music sound;
    if (!sound.openFromFile("Audio\\click.mp3"))
    {
        return 1;
    }

    sf::Texture TextureBack;
    if (!TextureBack.loadFromFile("Texture\\images.jpg"))
    {
        return 1;
    }

    sf::Texture TextureNumber;
    if (!TextureNumber.loadFromFile("Texture\\Number.png"))
    {
        return 1;
    }

    sf::Image cursorImage;
    if (!cursorImage.loadFromFile("Icons\\cursor.png"))
    {
        return 1;
    }

    sf::Image icon;
    if (!icon.loadFromFile("Icons\\icons.png"))
    {
        return 1;
    }

    sf::Texture WindowInstruction;
    if (!WindowInstruction.loadFromFile("Texture\\WindowInstruction.png"))
    {
        return 1;
    }

    sf::Font FontArimoSemiBold;
    if (!FontArimoSemiBold.loadFromFile("Font\\Arimo-SemiBold.ttf"))
    {
        return 1;
    }

    sf::Font FontExplanatory;
    if (!FontExplanatory.loadFromFile("Font\\PTF75F.ttf"))
    {
        return 1;
    }

    sf::Font FontCalibril;
    if (!FontCalibril.loadFromFile("Font\\calibril.ttf"))
    {
        return 1;
    }

    sf::Texture AnimationClick;
    if (!AnimationClick.loadFromFile("Texture\\AnimationClick.png"))
    {
        return 1;
    }

    sf::Texture TextureGame;
    if (!TextureGame.loadFromFile("Texture\\Game.png"))
    {
        return 1;
    }

    sf::Texture TextureInstruction;
    if (!TextureInstruction.loadFromFile("Texture\\Instruction.png"))
    {
        return 1;
    }

    sf::Texture TextureLanguage;
    if (!TextureLanguage.loadFromFile("Texture\\Language.png"))
    {
        return 1;
    }

    sf::Texture TextureExit;
    if (!TextureExit.loadFromFile("Texture\\Exit.png"))
    {
        return 1;
    }

    sf::Vector2u clickSpot(15, 6);
    sf::Cursor cursor;
    if (!cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), clickSpot))
    {
        return 1;
    }

    sf::Sprite SpriteBack;
    sf::Vector2u textureSize = TextureBack.getSize();
    sf::Vector2u windowSize = window.getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    SpriteBack.setTexture(TextureBack);
    SpriteBack.setScale(scaleX, scaleY);

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Sprite SpriteNumber10;
    SpriteNumber10.setTexture(TextureNumber);
    SpriteNumber10.setScale(00.2, 00.2);
    SpriteNumber10.setPosition(70, 170);

    sf::Sprite SpriteNumber20;
    SpriteNumber20.setTexture(TextureNumber);
    SpriteNumber20.setScale(00.2, 00.2);
    SpriteNumber20.setPosition(460, 170);

    sf::Sprite SpriteNumber30;
    SpriteNumber30.setTexture(TextureNumber);
    SpriteNumber30.setScale(00.2, 00.2);
    SpriteNumber30.setPosition(850, 170);

    sf::Sprite SpriteNumber40;
    SpriteNumber40.setTexture(TextureNumber);
    SpriteNumber40.setScale(00.2, 00.2);
    SpriteNumber40.setPosition(1230, 170);

    sf::Sprite SpriteNumber50;
    SpriteNumber50.setTexture(TextureNumber);
    SpriteNumber50.setScale(00.2, 00.2);
    SpriteNumber50.setPosition(1620, 170);

    sf::Sprite SpriteNumber60;
    SpriteNumber60.setTexture(TextureNumber);
    SpriteNumber60.setScale(00.2, 00.2);
    SpriteNumber60.setPosition(70, 360);

    sf::Sprite SpriteNumber70;
    SpriteNumber70.setTexture(TextureNumber);
    SpriteNumber70.setScale(00.2, 00.2);
    SpriteNumber70.setPosition(460, 360);

    sf::Sprite SpriteNumber80;
    SpriteNumber80.setTexture(TextureNumber);
    SpriteNumber80.setScale(00.2, 00.2);
    SpriteNumber80.setPosition(850, 360);

    sf::Sprite SpriteNumber90;
    SpriteNumber90.setTexture(TextureNumber);
    SpriteNumber90.setScale(00.2, 00.2);
    SpriteNumber90.setPosition(1230, 360);

    sf::Sprite SpriteNumber100;
    SpriteNumber100.setTexture(TextureNumber);
    SpriteNumber100.setScale(00.2, 00.2);
    SpriteNumber100.setPosition(1620, 360);

    sf::Sprite SpriteExit;
    SpriteExit.setTexture(TextureExit);
    SpriteExit.setScale(00.2, 00.2);
    SpriteExit.setPosition(70, 550);

    sf::Sprite SpriteGame;
    SpriteGame.setTexture(TextureGame);
    SpriteGame.setScale(00.2, 00.2);
    SpriteGame.setPosition(460, 550);

    sf::Sprite SpriteNumber110;
    SpriteNumber110.setTexture(TextureNumber);
    SpriteNumber110.setScale(00.2, 00.2);
    SpriteNumber110.setPosition(850, 550);

    sf::Sprite SpriteMenu;
    SpriteMenu.setTexture(TextureInstruction);
    SpriteMenu.setScale(00.2, 00.2);
    SpriteMenu.setPosition(1230, 550);

    sf::Sprite SpriteLanguage;
    SpriteLanguage.setTexture(TextureLanguage);
    SpriteLanguage.setScale(00.2, 00.2);
    SpriteLanguage.setPosition(1620, 550);

    sf::Sprite SpriteInstruction;
    SpriteInstruction.setTexture(WindowInstruction);
    SpriteInstruction.setScale(1.52, 0.3);
    SpriteInstruction.setPosition(80, 760);

    sf::Text TextHeading;
    TextHeading.setFont(FontArimoSemiBold);
    TextHeading.setString(L"Valet blevк");
    TextHeading.setCharacterSize(75.6);
    TextHeading.setFillColor(sf::Color::White);
    TextHeading.setPosition(650, 30);

    sf::Text TextNumber10;
    TextNumber10.setFont(FontArimoSemiBold);
    TextNumber10.setString(L"10");
    TextNumber10.setCharacterSize(80);
    TextNumber10.setFillColor(sf::Color::White);
    TextNumber10.setPosition(145, 180);

    sf::Text TextNumber20;
    TextNumber20.setFont(FontArimoSemiBold);
    TextNumber20.setString(L"20");
    TextNumber20.setCharacterSize(80);
    TextNumber20.setFillColor(sf::Color::White);
    TextNumber20.setPosition(535, 180);

    sf::Text TextNumber30;
    TextNumber30.setFont(FontArimoSemiBold);
    TextNumber30.setString(L"30");
    TextNumber30.setCharacterSize(80);
    TextNumber30.setFillColor(sf::Color::White);
    TextNumber30.setPosition(925, 180);

    sf::Text TextNumber40;
    TextNumber40.setFont(FontArimoSemiBold);
    TextNumber40.setString(L"40");
    TextNumber40.setCharacterSize(80);
    TextNumber40.setFillColor(sf::Color::White);
    TextNumber40.setPosition(1305, 180);

    sf::Text TextNumber50;
    TextNumber50.setFont(FontArimoSemiBold);
    TextNumber50.setString(L"50");
    TextNumber50.setCharacterSize(80);
    TextNumber50.setFillColor(sf::Color::White);
    TextNumber50.setPosition(1695, 180);

    sf::Text TextNumber60;
    TextNumber60.setFont(FontArimoSemiBold);
    TextNumber60.setString(L"60");
    TextNumber60.setCharacterSize(80);
    TextNumber60.setFillColor(sf::Color::White);
    TextNumber60.setPosition(145, 370);

    sf::Text TextNumber70;
    TextNumber70.setFont(FontArimoSemiBold);
    TextNumber70.setString(L"70");
    TextNumber70.setCharacterSize(80);
    TextNumber70.setFillColor(sf::Color::White);
    TextNumber70.setPosition(535, 370);

    sf::Text TextNumber80;
    TextNumber80.setFont(FontArimoSemiBold);
    TextNumber80.setString(L"80");
    TextNumber80.setCharacterSize(80);
    TextNumber80.setFillColor(sf::Color::White);
    TextNumber80.setPosition(925, 370);

    sf::Text TextNumber90;
    TextNumber90.setFont(FontArimoSemiBold);
    TextNumber90.setString(L"90");
    TextNumber90.setCharacterSize(80);
    TextNumber90.setFillColor(sf::Color::White);
    TextNumber90.setPosition(1300, 370);

    sf::Text TextNumber100;
    TextNumber100.setFont(FontArimoSemiBold);
    TextNumber100.setString(L"100");
    TextNumber100.setCharacterSize(80);
    TextNumber100.setFillColor(sf::Color::White);
    TextNumber100.setPosition(1670, 370);

    sf::Text TextNumber110;
    TextNumber110.setFont(FontArimoSemiBold);
    TextNumber110.setString(L"110");
    TextNumber110.setCharacterSize(80);
    TextNumber110.setFillColor(sf::Color::White);
    TextNumber110.setPosition(900, 560);

    sf::Text TextExit;
    TextExit.setFont(FontCalibril);
    TextExit.setString(L"Avsluta spelet");
    TextExit.setCharacterSize(45);
    TextExit.setFillColor(sf::Color::White);
    TextExit.setPosition(75, 580);

    sf::Text TextGame;
    TextGame.setFont(FontCalibril);
    TextGame.setString(L"Start\n       spelet\n   nytt");
    TextGame.setCharacterSize(35);
    TextGame.setFillColor(sf::Color::White);
    TextGame.setPosition(500, 550);

    sf::Text TextMenu;
    TextMenu.setFont(FontCalibril);
    TextMenu.setString(L"Återvända\n          till\n       meny");
    TextMenu.setCharacterSize(35);
    TextMenu.setFillColor(sf::Color::White);
    TextMenu.setPosition(1250, 550);

    sf::Text TextLanguage;
    TextLanguage.setFont(FontCalibril);
    TextLanguage.setString(L"Välja\n   den andra\n   språk");
    TextLanguage.setCharacterSize(35);
    TextLanguage.setFillColor(sf::Color::White);
    TextLanguage.setPosition(1680, 550);

    sf::Text TextExplanatory;
    TextExplanatory.setFont(FontCalibril);
    TextExplanatory.setString(L"                     Välj insatsbeloppet för vidare spel.\n(För att välja insatsbeloppet måste du klicka på fältet med ett nummer.)");
    TextExplanatory.setCharacterSize(60);
    TextExplanatory.setFillColor(sf::Color::White);
    TextExplanatory.setPosition(120, 780);

    int summkost = sumkost;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(SpriteBack);
        window.draw(SpriteNumber10);
        window.draw(SpriteNumber20);
        window.draw(SpriteNumber30);
        window.draw(SpriteNumber40);
        window.draw(SpriteNumber50);
        window.draw(SpriteNumber60);
        window.draw(SpriteNumber70);
        window.draw(SpriteNumber80);
        window.draw(SpriteNumber90);
        window.draw(SpriteNumber100);
        window.draw(SpriteNumber110);
        window.draw(SpriteInstruction);
        window.draw(SpriteExit);
        window.draw(SpriteGame);
        window.draw(SpriteMenu);
        window.draw(SpriteLanguage);
        window.draw(TextNumber10);
        window.draw(TextNumber20);
        window.draw(TextNumber30);
        window.draw(TextNumber40);
        window.draw(TextNumber50);
        window.draw(TextNumber60);
        window.draw(TextNumber70);
        window.draw(TextNumber80);
        window.draw(TextNumber90);
        window.draw(TextNumber100);
        window.draw(TextNumber110);
        window.draw(TextHeading);
        window.draw(TextExplanatory);
        window.draw(TextExit);
        window.draw(TextGame);
        window.draw(TextMenu);
        window.draw(TextLanguage);
        window.setMouseCursor(cursor);

        sf::Vector2i MousePozition = sf::Mouse::getPosition(window);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber10.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(70, 170);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber10);
                int stavka_number = 10;
                window.display();
                Sleep(500);
                window.close();
                gameSw(stavka_number, summkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber20.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(460, 170);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber20);
                int stavka_number = 20;
                window.display();
                Sleep(500);
                window.close();
                gameSw(stavka_number, summkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber30.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(850, 170);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber30);
                int stavka_number = 30;
                window.display();
                Sleep(500);
                window.close();
                gameSw(stavka_number, summkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber40.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(1230, 170);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber40);
                int stavka_number = 40;
                window.display();
                Sleep(500);
                window.close();
                gameSw(stavka_number, summkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber50.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(1620, 170);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber50);
                int stavka_number = 50;
                window.display();
                Sleep(500);
                window.close();
                gameSw(stavka_number, summkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber60.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(70, 360);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber60);
                int stavka_number = 60;
                window.display();
                Sleep(500);
                window.close();
                gameSw(stavka_number, summkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber70.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(460, 360);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber70);
                int stavka_number = 70;
                window.display();
                Sleep(500);
                window.close();
                gameSw(stavka_number, summkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber80.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(850, 360);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber80);
                int stavka_number = 80;
                window.display();
                Sleep(500);
                window.close();
                gameSw(stavka_number, summkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber90.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(1230, 360);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber90);
                int stavka_number = 90;
                window.display();
                Sleep(500);
                window.close();
                gameSw(stavka_number, summkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber100.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(1620, 360);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber100);
                int stavka_number = 100;
                window.display();
                Sleep(500);
                window.close();
                gameSw(stavka_number, summkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNumber110.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(850, 550);
                window.draw(SpriteAnimationClick);
                window.draw(TextNumber110);
                int stavka_number = 110;
                window.display();
                Sleep(500);
                window.close();
                gameSw(stavka_number, summkost);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteGame.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(460, 550);
                window.draw(SpriteAnimationClick);
                window.draw(TextGame);
                window.display();
                Sleep(500);
                window.close();
                ViborKostSw();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteExit.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(70, 550);
                window.draw(SpriteAnimationClick);
                window.draw(TextExit);
                window.display();
                Sleep(500);
                window.close();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteMenu.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(1230, 550);
                window.draw(SpriteAnimationClick);
                window.draw(TextMenu);
                window.display();
                Sleep(500);
                window.close();
                MenuSw();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteLanguage.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2);
                SpriteAnimationClick.setPosition(1620, 550);
                window.draw(SpriteAnimationClick);
                window.draw(TextLanguage);
                window.display();
                Sleep(500);
                window.close();
                main();
            }
        }
        window.display();
    }
    return 0;
}

int ResultSw(int summkost, int stavka_number)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), L"Ben", sf::Style::Close);
    window.setFramerateLimit(144);

    sf::Music sound;
    if (!sound.openFromFile("Audio\\click.mp3"))
    {
        return 1;
    }

    sf::Texture TextureBack;
    if (!TextureBack.loadFromFile("Texture\\images.jpg"))
    {
        return 1;
    }

    sf::Image cursorImage;
    if (!cursorImage.loadFromFile("Icons\\cursor.png"))
    {
        return 1;
    }

    sf::Image icon;
    if (!icon.loadFromFile("Icons\\icons.png"))
    {
        return 1;
    }

    sf::Font FontArimoSemiBold;
    if (!FontArimoSemiBold.loadFromFile("Font\\Arimo-SemiBold.ttf"))
    {
        return 1;
    }

    sf::Font FontExplanatory;
    if (!FontExplanatory.loadFromFile("Font\\PTF75F.ttf"))
    {
        return 1;
    }

    sf::Font FontCalibril;
    if (!FontCalibril.loadFromFile("Font\\calibril.ttf"))
    {
        return 1;
    }

    sf::Texture WindowInstruction;
    if (!WindowInstruction.loadFromFile("Texture\\WindowInstruction.png"))
    {
        return 1;
    }

    sf::Texture AnimationClick;
    if (!AnimationClick.loadFromFile("Texture\\AnimationClick.png"))
    {
        return 1;
    }

    sf::Texture TextureGame;
    if (!TextureGame.loadFromFile("Texture\\Game.png"))
    {
        return 1;
    }

    sf::Texture TextureInstruction;
    if (!TextureInstruction.loadFromFile("Texture\\Instruction.png"))
    {
        return 1;
    }

    sf::Texture TextureLanguage;
    if (!TextureLanguage.loadFromFile("Texture\\Language.png"))
    {
        return 1;
    }

    sf::Texture TextureExit;
    if (!TextureExit.loadFromFile("Texture\\Exit.png"))
    {
        return 1;
    }

    sf::Vector2u clickSpot(15, 6);
    sf::Cursor cursor;
    if (!cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), clickSpot))
    {
        return 1;
    }

    sf::Sprite SpriteBack;
    sf::Vector2u textureSize = TextureBack.getSize();
    sf::Vector2u windowSize = window.getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    SpriteBack.setTexture(TextureBack);
    SpriteBack.setScale(scaleX, scaleY);

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Sprite SpriteInstruction;
    SpriteInstruction.setTexture(WindowInstruction);
    SpriteInstruction.setScale(1.6, 1.1);
    SpriteInstruction.setPosition(30, 100);

    sf::Sprite SpriteGame;
    SpriteGame.setTexture(TextureGame);
    SpriteGame.setScale(00.3, 00.2);
    SpriteGame.setPosition(1500, 840);

    sf::Sprite SpriteLanguage;
    SpriteLanguage.setTexture(TextureLanguage);
    SpriteLanguage.setScale(00.3, 00.2);
    SpriteLanguage.setPosition(540, 840);

    sf::Sprite SpriteMenu;
    SpriteMenu.setTexture(TextureInstruction);
    SpriteMenu.setScale(00.3, 00.2);
    SpriteMenu.setPosition(1040, 840);

    sf::Sprite SpriteExit;
    SpriteExit.setTexture(TextureExit);
    SpriteExit.setScale(00.3, 00.2);
    SpriteExit.setPosition(80, 840);

    sf::Text TextHeading;
    TextHeading.setFont(FontArimoSemiBold);
    TextHeading.setString(L"Resultatet av spelet");
    TextHeading.setCharacterSize(75.6);
    TextHeading.setFillColor(sf::Color::White);
    TextHeading.setPosition(740, 0);

    sf::Text TextGame;
    TextGame.setFont(FontCalibril);
    TextGame.setString(L"Starta spelet");
    TextGame.setCharacterSize(45);
    TextGame.setFillColor(sf::Color::White);
    TextGame.setPosition(1540, 875);

    sf::Text TextExit;
    TextExit.setFont(FontCalibril);
    TextExit.setString(L"Avsluta spelet");
    TextExit.setCharacterSize(45);
    TextExit.setFillColor(sf::Color::White);
    TextExit.setPosition(140, 875);

    sf::Text TextLanguage;
    TextLanguage.setFont(FontCalibril);
    TextLanguage.setString(L"Språkval");
    TextLanguage.setCharacterSize(45);
    TextLanguage.setFillColor(sf::Color::White);
    TextLanguage.setPosition(610, 875);

    sf::Text TextMenu;
    TextMenu.setFont(FontCalibril);
    TextMenu.setString(L"Återgå till menyn");
    TextMenu.setCharacterSize(30);
    TextMenu.setFillColor(sf::Color::White);
    TextMenu.setPosition(1070, 885);

    srand(static_cast<unsigned>(time(nullptr)));

    int kost1;
    kost1 = rand() % 6 + 1;

    int kost2;
    kost2 = rand() % 6 + 1;

    int number_sum_kost = summkost, stavka = stavka_number;

    int sum_kost_console = kost1 + kost2;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(SpriteBack);
        window.draw(TextHeading);
        window.draw(SpriteInstruction);
        window.draw(SpriteGame);
        window.draw(SpriteExit);
        window.draw(TextGame);
        window.draw(TextExit);
        window.draw(SpriteLanguage);
        window.draw(TextLanguage);
        window.draw(SpriteMenu);
        window.draw(TextMenu);
        window.setMouseCursor(cursor);

        sf::Vector2i MousePozition = sf::Mouse::getPosition(window);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteGame.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.3, 00.2);
                SpriteAnimationClick.setPosition(1500, 840);
                window.draw(SpriteAnimationClick);
                window.draw(TextGame);
                window.display();
                Sleep(500);
                window.close();
                ViborKostSw();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteLanguage.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.3, 00.2);
                SpriteAnimationClick.setPosition(540, 840);
                window.draw(SpriteAnimationClick);
                window.draw(TextLanguage);
                window.display();
                Sleep(500);
                window.close();
                main();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteExit.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.3, 00.2);
                SpriteAnimationClick.setPosition(80, 840);
                window.draw(SpriteAnimationClick);
                window.draw(TextExit);
                window.display();
                Sleep(500);
                window.close();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteMenu.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sound.play();
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.3, 00.2);
                SpriteAnimationClick.setPosition(1040, 840);
                window.draw(SpriteAnimationClick);
                window.draw(TextMenu);
                window.display();
                Sleep(500);
                window.close();
                MenuSw();
            }
        }

        if (number_sum_kost < 7.2)
        {
            if (sum_kost_console < number_sum_kost)
            {
                sf::Text TextHeading1;
                TextHeading1.setFont(FontArimoSemiBold);
                TextHeading1.setString(L"Du vann vadet!");
                TextHeading1.setCharacterSize(50);
                TextHeading1.setFillColor(sf::Color::White);
                TextHeading1.setPosition(740, 200);

                int stavka_conclusion = stavka * 2;

                sf::Text TextHeading2;
                TextHeading2.setFont(FontArimoSemiBold);
                std::wstringstream ws1;
                ws1 << L"Dina ben föll ut " << kost1 << L" och " << kost2 << ".";
                TextHeading2.setString(ws1.str());
                TextHeading2.setCharacterSize(50);
                TextHeading2.setFillColor(sf::Color::White);
                TextHeading2.setPosition(700, 300);

                sf::Text TextHeading3;
                TextHeading3.setFont(FontArimoSemiBold);
                std::wstringstream ws2;
                ws2 << L"Сума кісток яких ви обрали: " << number_sum_kost << ".";
                TextHeading3.setString(ws2.str());
                TextHeading3.setCharacterSize(50);
                TextHeading3.setFillColor(sf::Color::White);
                TextHeading3.setPosition(640, 400);

                sf::Text TextHeading4;
                TextHeading4.setFont(FontArimoSemiBold);
                std::wstringstream ws3;
                ws3 << L"Summan är: " << sum_kost_console << ".";
                TextHeading4.setString(ws3.str());
                TextHeading4.setCharacterSize(50);
                TextHeading4.setFillColor(sf::Color::White);
                TextHeading4.setPosition(760, 500);

                sf::Text TextHeading;
                TextHeading.setFont(FontArimoSemiBold);
                std::wstringstream ws;
                ws << L"Din insats har fördubblats, din insats är = " << stavka_conclusion << ".";
                TextHeading.setString(ws.str());
                TextHeading.setCharacterSize(50);
                TextHeading.setFillColor(sf::Color::White);
                TextHeading.setPosition(180, 600);

                window.draw(TextHeading1);
                window.draw(TextHeading2);
                window.draw(TextHeading3);
                window.draw(TextHeading4);
                window.draw(TextHeading);

            }
        }

        if (number_sum_kost < 7.2)
        {
            if (sum_kost_console < 7.2)
            {
                if (sum_kost_console > number_sum_kost)
                {
                    sf::Text TextHeading1;
                    TextHeading1.setFont(FontArimoSemiBold);
                    TextHeading1.setString(L"Du vann vadet!");
                    TextHeading1.setCharacterSize(50);
                    TextHeading1.setFillColor(sf::Color::White);
                    TextHeading1.setPosition(740, 200);

                    int stavka_conclusion = stavka * 2;

                    sf::Text TextHeading2;
                    TextHeading2.setFont(FontArimoSemiBold);
                    std::wstringstream ws1;
                    ws1 << L"Dina ben föll ut " << kost1 << L" och " << kost2 << ".";
                    TextHeading2.setString(ws1.str());
                    TextHeading2.setCharacterSize(50);
                    TextHeading2.setFillColor(sf::Color::White);
                    TextHeading2.setPosition(700, 300);

                    sf::Text TextHeading3;
                    TextHeading3.setFont(FontArimoSemiBold);
                    std::wstringstream ws2;
                    ws2 << L"Summan av tärningarna du valde: " << number_sum_kost << ".";
                    TextHeading3.setString(ws2.str());
                    TextHeading3.setCharacterSize(50);
                    TextHeading3.setFillColor(sf::Color::White);
                    TextHeading3.setPosition(640, 400);

                    sf::Text TextHeading4;
                    TextHeading4.setFont(FontArimoSemiBold);
                    std::wstringstream ws3;
                    ws3 << L"Summan är: " << sum_kost_console << ".";
                    TextHeading4.setString(ws3.str());
                    TextHeading4.setCharacterSize(50);
                    TextHeading4.setFillColor(sf::Color::White);
                    TextHeading4.setPosition(760, 500);

                    sf::Text TextHeading;
                    TextHeading.setFont(FontArimoSemiBold);
                    std::wstringstream ws;
                    ws << L"Din insats har fördubblats, din insats är = " << stavka_conclusion << ".";
                    TextHeading.setString(ws.str());
                    TextHeading.setCharacterSize(50);
                    TextHeading.setFillColor(sf::Color::White);
                    TextHeading.setPosition(180, 600);

                    window.draw(TextHeading1);
                    window.draw(TextHeading2);
                    window.draw(TextHeading3);
                    window.draw(TextHeading4);
                    window.draw(TextHeading);
                }
            }
        }

        if (number_sum_kost < 7.2)
        {
            if (sum_kost_console > 7.8)
            {
                sf::Text TextHeading1;
                TextHeading1.setFont(FontArimoSemiBold);
                TextHeading1.setString(L"Du förlorade vadet!");
                TextHeading1.setCharacterSize(50);
                TextHeading1.setFillColor(sf::Color::White);
                TextHeading1.setPosition(740, 200);


                int stavka_conclusion = stavka * 0;

                sf::Text TextHeading2;
                TextHeading2.setFont(FontArimoSemiBold);
                std::wstringstream ws1;
                ws1 << L"Dina ben föll ut " << kost1 << L" och " << kost2 << ".";
                TextHeading2.setString(ws1.str());
                TextHeading2.setCharacterSize(50);
                TextHeading2.setFillColor(sf::Color::White);
                TextHeading2.setPosition(700, 300);

                sf::Text TextHeading3;
                TextHeading3.setFont(FontArimoSemiBold);
                std::wstringstream ws2;
                ws2 << L"Summan av tärningarna du valde: " << number_sum_kost << ".";
                TextHeading3.setString(ws2.str());
                TextHeading3.setCharacterSize(50);
                TextHeading3.setFillColor(sf::Color::White);
                TextHeading3.setPosition(640, 400);

                sf::Text TextHeading4;
                TextHeading4.setFont(FontArimoSemiBold);
                std::wstringstream ws3;
                ws3 << L"Summan är: " << sum_kost_console << ".";
                TextHeading4.setString(ws3.str());
                TextHeading4.setCharacterSize(50);
                TextHeading4.setFillColor(sf::Color::White);
                TextHeading4.setPosition(760, 500);

                sf::Text TextHeading;
                TextHeading.setFont(FontArimoSemiBold);
                std::wstringstream ws;
                ws << L"Ditt bud har annullerats, ditt bud är = " << stavka_conclusion << ".";
                TextHeading.setString(ws.str());
                TextHeading.setCharacterSize(50);
                TextHeading.setFillColor(sf::Color::White);
                TextHeading.setPosition(100, 600);

                window.draw(TextHeading1);
                window.draw(TextHeading2);
                window.draw(TextHeading3);
                window.draw(TextHeading4);
                window.draw(TextHeading);
            }
        }

        if (number_sum_kost == sum_kost_console)
        {
            sf::Text TextHeading1;
            TextHeading1.setFont(FontArimoSemiBold);
            TextHeading1.setString(L"Du har vunnit en satsning och kommer att vinna en satsning på fyra till!");
            TextHeading1.setCharacterSize(50);
            TextHeading1.setFillColor(sf::Color::White);
            TextHeading1.setPosition(740, 200);

            int stavka_conclusion = stavka * 4;

            sf::Text TextHeading2;
            TextHeading2.setFont(FontArimoSemiBold);
            std::wstringstream ws1;
            ws1 << L"Dina ben föll ut " << kost1 << L" och " << kost2 << ".";
            TextHeading2.setString(ws1.str());
            TextHeading2.setCharacterSize(50);
            TextHeading2.setFillColor(sf::Color::White);
            TextHeading2.setPosition(700, 300);

            sf::Text TextHeading3;
            TextHeading3.setFont(FontArimoSemiBold);
            std::wstringstream ws2;
            ws2 << L"Summan av tärningarna du valde: " << number_sum_kost << ".";
            TextHeading3.setString(ws2.str());
            TextHeading3.setCharacterSize(50);
            TextHeading3.setFillColor(sf::Color::White);
            TextHeading3.setPosition(640, 400);

            sf::Text TextHeading4;
            TextHeading4.setFont(FontArimoSemiBold);
            std::wstringstream ws3;
            ws3 << L"Summan är: " << sum_kost_console << ".";
            TextHeading4.setString(ws3.str());
            TextHeading4.setCharacterSize(50);
            TextHeading4.setFillColor(sf::Color::White);
            TextHeading4.setPosition(760, 500);

            sf::Text TextHeading;
            TextHeading.setFont(FontArimoSemiBold);
            std::wstringstream ws;
            ws << L"Ваша сochвка збiльшилася в четверо, ваша сochвка сochновить = " << stavka_conclusion << ".";
            TextHeading.setString(ws.str());
            TextHeading.setCharacterSize(50);
            TextHeading.setFillColor(sf::Color::White);
            TextHeading.setPosition(180, 600);

            window.draw(TextHeading1);
            window.draw(TextHeading2);
            window.draw(TextHeading3);
            window.draw(TextHeading4);
            window.draw(TextHeading);
        }

        if (number_sum_kost > 7.8)
        {
            if (sum_kost_console > 7.8)
            {
                if (sum_kost_console < number_sum_kost)
                {
                    sf::Text TextHeading1;
                    TextHeading1.setFont(FontArimoSemiBold);
                    TextHeading1.setString(L"Du vann vadet!");
                    TextHeading1.setCharacterSize(50);
                    TextHeading1.setFillColor(sf::Color::White);
                    TextHeading1.setPosition(740, 200);

                    int stavka_conclusion = stavka * 2;

                    sf::Text TextHeading2;
                    TextHeading2.setFont(FontArimoSemiBold);
                    std::wstringstream ws1;
                    ws1 << L"Dina ben föll ut " << kost1 << L" och " << kost2 << ".";
                    TextHeading2.setString(ws1.str());
                    TextHeading2.setCharacterSize(50);
                    TextHeading2.setFillColor(sf::Color::White);
                    TextHeading2.setPosition(700, 300);

                    sf::Text TextHeading3;
                    TextHeading3.setFont(FontArimoSemiBold);
                    std::wstringstream ws2;
                    ws2 << L"Summan av tärningarna du valde: " << number_sum_kost << ".";
                    TextHeading3.setString(ws2.str());
                    TextHeading3.setCharacterSize(50);
                    TextHeading3.setFillColor(sf::Color::White);
                    TextHeading3.setPosition(640, 400);

                    sf::Text TextHeading4;
                    TextHeading4.setFont(FontArimoSemiBold);
                    std::wstringstream ws3;
                    ws3 << L"Summan är: " << sum_kost_console << ".";
                    TextHeading4.setString(ws3.str());
                    TextHeading4.setCharacterSize(50);
                    TextHeading4.setFillColor(sf::Color::White);
                    TextHeading4.setPosition(760, 500);

                    sf::Text TextHeading;
                    TextHeading.setFont(FontArimoSemiBold);
                    std::wstringstream ws;
                    ws << L"Din insats har fördubblats, din insats är = " << stavka_conclusion << ".";
                    TextHeading.setString(ws.str());
                    TextHeading.setCharacterSize(50);
                    TextHeading.setFillColor(sf::Color::White);
                    TextHeading.setPosition(180, 600);

                    window.draw(TextHeading1);
                    window.draw(TextHeading2);
                    window.draw(TextHeading3);
                    window.draw(TextHeading4);
                    window.draw(TextHeading);
                }
            }
        }

        if (number_sum_kost > 7.8)
        {
            if (sum_kost_console > number_sum_kost)
            {
                sf::Text TextHeading1;
                TextHeading1.setFont(FontArimoSemiBold);
                TextHeading1.setString(L"Du vann vadet");
                TextHeading1.setCharacterSize(50);
                TextHeading1.setFillColor(sf::Color::White);
                TextHeading1.setPosition(740, 200);

                int stavka_conclusion = stavka * 2;

                sf::Text TextHeading2;
                TextHeading2.setFont(FontArimoSemiBold);
                std::wstringstream ws1;
                ws1 << L"Dina ben föll ut " << kost1 << L" och " << kost2 << ".";
                TextHeading2.setString(ws1.str());
                TextHeading2.setCharacterSize(50);
                TextHeading2.setFillColor(sf::Color::White);
                TextHeading2.setPosition(700, 300);

                sf::Text TextHeading3;
                TextHeading3.setFont(FontArimoSemiBold);
                std::wstringstream ws2;
                ws2 << L"Summan av tärningarna du valde: " << number_sum_kost << ".";
                TextHeading3.setString(ws2.str());
                TextHeading3.setCharacterSize(50);
                TextHeading3.setFillColor(sf::Color::White);
                TextHeading3.setPosition(640, 400);

                sf::Text TextHeading4;
                TextHeading4.setFont(FontArimoSemiBold);
                std::wstringstream ws3;
                ws3 << L"Summan är: " << sum_kost_console << ".";
                TextHeading4.setString(ws3.str());
                TextHeading4.setCharacterSize(50);
                TextHeading4.setFillColor(sf::Color::White);
                TextHeading4.setPosition(760, 500);

                sf::Text TextHeading;
                TextHeading.setFont(FontArimoSemiBold);
                std::wstringstream ws;
                ws << L"Din insats har fördubblats, din insats är = " << stavka_conclusion << ".";
                TextHeading.setString(ws.str());
                TextHeading.setCharacterSize(50);
                TextHeading.setFillColor(sf::Color::White);
                TextHeading.setPosition(180, 600);

                window.draw(TextHeading1);
                window.draw(TextHeading2);
                window.draw(TextHeading3);
                window.draw(TextHeading4);
                window.draw(TextHeading);
            }
        }

        if (number_sum_kost > 7.8)
        {
            if (sum_kost_console < 7.2)
            {
                sf::Text TextHeading1;
                TextHeading1.setFont(FontArimoSemiBold);
                TextHeading1.setString(L"Du förlorade vadet!");
                TextHeading1.setCharacterSize(50);
                TextHeading1.setFillColor(sf::Color::White);
                TextHeading1.setPosition(740, 200);

                int stavka_conclusion = stavka * 0;

                sf::Text TextHeading2;
                TextHeading2.setFont(FontArimoSemiBold);
                std::wstringstream ws1;
                ws1 << L"Dina ben föll ut " << kost1 << L" och " << kost2 << ".";
                TextHeading2.setString(ws1.str());
                TextHeading2.setCharacterSize(50);
                TextHeading2.setFillColor(sf::Color::White);
                TextHeading2.setPosition(700, 300);

                sf::Text TextHeading3;
                TextHeading3.setFont(FontArimoSemiBold);
                std::wstringstream ws2;
                ws2 << L"Summan av tärningarna du valde: " << number_sum_kost << ".";
                TextHeading3.setString(ws2.str());
                TextHeading3.setCharacterSize(50);
                TextHeading3.setFillColor(sf::Color::White);
                TextHeading3.setPosition(640, 400);

                sf::Text TextHeading4;
                TextHeading4.setFont(FontArimoSemiBold);
                std::wstringstream ws3;
                ws3 << L"Summan är: " << sum_kost_console << ".";
                TextHeading4.setString(ws3.str());
                TextHeading4.setCharacterSize(50);
                TextHeading4.setFillColor(sf::Color::White);
                TextHeading4.setPosition(760, 500);

                sf::Text TextHeading;
                TextHeading.setFont(FontArimoSemiBold);
                std::wstringstream ws;
                ws << L"Ditt bud har annullerats, ditt bud är = " << stavka_conclusion << ".";
                TextHeading.setString(ws.str());
                TextHeading.setCharacterSize(50);
                TextHeading.setFillColor(sf::Color::White);
                TextHeading.setPosition(100, 600);

                window.draw(TextHeading1);
                window.draw(TextHeading2);
                window.draw(TextHeading3);
                window.draw(TextHeading4);
                window.draw(TextHeading);
            }
        }
        window.display();
    }
    return 0;
}

int gameSw(int stavka_number, int summkost)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), L"Ben", sf::Style::Close);
    window.setFramerateLimit(144);

    std::vector<sf::Texture> textures(6);
    if (!textures[0].loadFromFile("Texture\\Texture1.bmp") ||
        !textures[1].loadFromFile("Texture\\Texture2.bmp") ||
        !textures[2].loadFromFile("Texture\\Texture3.bmp") ||
        !textures[3].loadFromFile("Texture\\Texture4.bmp") ||
        !textures[4].loadFromFile("Texture\\Texture5.bmp") ||
        !textures[5].loadFromFile("Texture\\Texture6.bmp"))

    {
        return 1;
    }

    sf::Music sound;
    if (!sound.openFromFile("Audio\\click.mp3"))
    {
        return 1;
    }

    sf::Music soundBones;
    if (!soundBones.openFromFile("Audio\\igrkosti.mp3"))
    {
        return 1;
    }

    sf::Texture TextureBack;
    if (!TextureBack.loadFromFile("Texture\\texture_back.jpg"))
    {
        return 1;
    }

    sf::Image cursorImage;
    if (!cursorImage.loadFromFile("Icons\\cursor.png"))
    {
        return 1;
    }

    sf::Image icon;
    if (!icon.loadFromFile("Icons\\icons.png"))
    {
        return 1;
    }

    sf::Vector2u clickSpot(15, 6);
    sf::Cursor cursor;
    if (!cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), clickSpot))
    {
        return 1;
    }

    int stavka = stavka_number;
    int summbones = summkost;

    sf::Sprite SpriteBack;
    sf::Vector2u textureSize = TextureBack.getSize();
    sf::Vector2u windowSize = window.getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    SpriteBack.setTexture(TextureBack);
    SpriteBack.setScale(scaleX, scaleY);

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Sprite sprite1;
    sf::Sprite sprite2;
    sprite1.setPosition(100, 100);
    sprite2.setPosition(900, 500);

    sf::Clock clock;
    sf::Clock closeClock;
    float switchTime = 0.5f;
    int currentTexture = 0;

    float speed = 3;
    sf::Vector2f direction1(1.0f, 1.0f);
    sf::Vector2f direction2(-1.0f, 1.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (clock.getElapsedTime().asSeconds() > switchTime)
        {
            currentTexture = (currentTexture + 1) % textures.size();
            sprite1.setTexture(textures[currentTexture]);
            sprite2.setTexture(textures[(currentTexture + 3) % textures.size()]);
            clock.restart();
        }

        sprite1.move(direction1 * speed);
        sprite2.move(direction2 * speed);


        if (sprite1.getPosition().x > window.getSize().x - sprite1.getGlobalBounds().width || sprite1.getPosition().x < 0)
        {
            direction1.x = -direction1.x;
            soundBones.play();
        }
        if (sprite1.getPosition().y > window.getSize().y - sprite1.getGlobalBounds().height || sprite1.getPosition().y < 0)
        {
            direction1.y = -direction1.y;
            soundBones.play();
        }
        if (sprite2.getPosition().x > window.getSize().x - sprite2.getGlobalBounds().width || sprite2.getPosition().x < 0)
        {
            direction2.x = -direction2.x;
            soundBones.play();
        }
        if (sprite2.getPosition().y > window.getSize().y - sprite2.getGlobalBounds().height || sprite2.getPosition().y < 0)
        {
            direction2.y = -direction2.y;
            soundBones.play();
        }

        if (sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds()))
        {

            direction1 = -direction1;
            direction2 = -direction2;
            soundBones.play();
        }


        if (closeClock.getElapsedTime().asSeconds() > 10.0f)
        {
            window.close();
            ResultSw(summbones, stavka);
        }

        window.clear();
        window.draw(SpriteBack);
        window.draw(sprite1);
        window.draw(sprite2);
        window.setMouseCursor(cursor);
        window.display();
    }

    return 0;
}