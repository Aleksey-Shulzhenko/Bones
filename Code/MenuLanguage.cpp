#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>

int MenuUkraine();
int MenuRus();
int MenuBel();
int MenuHun();
int MenuPl();
int MenuGer();
int MenuSl();
int MenuSp();
int MenuEng();
int MenuCzh();
int MenuFr();
int MenuIt();
int MenuCro();
int MenuFin();
int MenuTyr();
int MenuKaz();
int MenuNor();
int MenuRom();
int MenuSer();
int MenuSw();

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Bones", sf::Style::Close);
    window.setFramerateLimit(144);

    sf::Image icon;
    if (!icon.loadFromFile("Icons\\icons.png"))
    {
        return 1;
    }

    sf::Music music;
    if (!music.openFromFile("Audio\\click.mp3"))
    {
        return 1;
    }

    sf::Texture TextureUkraineAnimation;
    if (!TextureUkraineAnimation.loadFromFile("Texture\\Ukraine_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureRussiaAnimation;
    if (!TextureRussiaAnimation.loadFromFile("Texture\\Russia_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureByelorussiaAnimation;
    if (!TextureByelorussiaAnimation.loadFromFile("Texture\\Byelorussia_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureHungaryAnimation;
    if (!TextureHungaryAnimation.loadFromFile("Texture\\Hungary_Animation.png"))
    {
        return 1;
    }

    sf::Texture TexturePolandAnimation;
    if (!TexturePolandAnimation.loadFromFile("Texture\\Poland_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureGermanyAnimation;
    if (!TextureGermanyAnimation.loadFromFile("Texture\\Germany_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureSlovakAnimation;
    if (!TextureSlovakAnimation.loadFromFile("Texture\\Slovak_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureSpanishAnimation;
    if (!TextureSpanishAnimation.loadFromFile("Texture\\Spanish_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureEnglishAnimation;
    if (!TextureEnglishAnimation.loadFromFile("Texture\\English_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureCzechAnimation;
    if (!TextureCzechAnimation.loadFromFile("Texture\\Czech_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureFrenchAnimation;
    if (!TextureFrenchAnimation.loadFromFile("Texture\\French_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureItalianAnimation;
    if (!TextureItalianAnimation.loadFromFile("Texture\\Italian_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureCrotiaAnimation;
    if (!TextureCrotiaAnimation.loadFromFile("Texture\\Crotia_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureFinnishAnimation;
    if (!TextureFinnishAnimation.loadFromFile("Texture\\Finnish_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureTurkeyAnimation;
    if (!TextureTurkeyAnimation.loadFromFile("Texture\\Turkey_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureKazakhAnimation;
    if (!TextureKazakhAnimation.loadFromFile("Texture\\Kazakh_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureNorwayAnimation;
    if (!TextureNorwayAnimation.loadFromFile("Texture\\Norway_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureRomaniaAnimation;
    if (!TextureRomaniaAnimation.loadFromFile("Texture\\Romania_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureSerbiaAnimation;
    if (!TextureSerbiaAnimation.loadFromFile("Texture\\Serbia_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureSwedenAnimation;
    if (!TextureSwedenAnimation.loadFromFile("Texture\\Sweden_Animation.png"))
    {
        return 1;
    }

    sf::Texture TextureBack;
    if (!TextureBack.loadFromFile("Texture\\texture_back.jpg"))
    {
        return 1;
    }

    sf::Font FontExplanatory; 
    if (!FontExplanatory.loadFromFile("Font\\PTF75F.ttf")) 
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

    sf::Texture TextureUkraine;
    if (!TextureUkraine.loadFromFile("Texture\\Ukraine.png"))
    {
        return 1;
    }

    sf::Texture TextureRussia;
    if (!TextureRussia.loadFromFile("Texture\\Russia.png"))
    {
        return 1;
    }

    sf::Texture TextureByelorussia;
    if (!TextureByelorussia.loadFromFile("Texture\\Byelorussia.png"))
    {
        return 1;
    }

    sf::Texture TextureHungary;
    if (!TextureHungary.loadFromFile("Texture\\Hungary.png"))
    {
        return 1;
    }

    sf::Texture TexturePoland;
    if (!TexturePoland.loadFromFile("Texture\\Poland.png"))
    {
        return 1;
    }

    sf::Texture TextureGermany;
    if (!TextureGermany.loadFromFile("Texture\\Germany.png"))
    {
        return 1;
    }

    sf::Texture TextureSlovak;
    if (!TextureSlovak.loadFromFile("Texture\\Slovak.png"))
    {
        return 1;
    }

    sf::Texture TextureSpanish;
    if (!TextureSpanish.loadFromFile("Texture\\Spanish.png"))
    {
        return 1;
    }

    sf::Texture TextureEnglish;
    if (!TextureEnglish.loadFromFile("Texture\\English.png"))
    {
        return 1;
    }

    sf::Texture TextureCzech;
    if (!TextureCzech.loadFromFile("Texture\\Czech.png"))
    {
        return 1;
    }

    sf::Texture TextureFrench;
    if (!TextureFrench.loadFromFile("Texture\\French.png"))
    {
        return 1;
    }

    sf::Texture TextureItalian;
    if (!TextureItalian.loadFromFile("Texture\\Italy.png"))
    {
        return 1;
    }

    sf::Texture TextureCroatia;
    if (!TextureCroatia.loadFromFile("Texture\\Croatia.png"))
    {
        return 1;
    }

    sf::Texture TextureFinnish;
    if (!TextureFinnish.loadFromFile("Texture\\Finnish.png"))
    {
        return 1;
    }

    sf::Texture TextureTurkey;
    if (!TextureTurkey.loadFromFile("Texture\\Tyrkey.png"))
    {
        return 1;
    }

    sf::Texture TextureKazakh;
    if (!TextureKazakh.loadFromFile("Texture\\Kazakhstan.png"))
    {
        return 1;
    }

    sf::Texture TextureNorway;
    if (!TextureNorway.loadFromFile("Texture\\Norway.png"))
    {
        return 1;
    }

    sf::Texture TextureRomania;
    if (!TextureRomania.loadFromFile("Texture\\Romania.png"))
    {
        return 1;
    }

    sf::Texture TextureSerbia;
    if (!TextureSerbia.loadFromFile("Texture\\Serbia.png"))
    {
        return 1;
    }

    sf::Texture TextureSweden;
    if (!TextureSweden.loadFromFile("Texture\\Sweden.png"))
    {
        return 1;
    }

    sf::Texture TextureExit;
    if (!TextureExit.loadFromFile("Texture\\Exit.png"))
    {
        return 1;
    }

    sf::Texture AnimationClick;
    if (!AnimationClick.loadFromFile("Texture\\AnimationClick.png"))
    {
        return 1;
    }

    if (!icon.loadFromFile("Icons\\icons.png"))
    {
        return 1;
    }
   
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    sf::Sprite SpriteBack;
    sf::Vector2u textureSize = TextureBack.getSize();
    sf::Vector2u windowSize = window.getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    SpriteBack.setTexture(TextureBack);
    SpriteBack.setScale(scaleX, scaleY);

    sf::Image cursorImage;
    cursorImage.loadFromFile("Icons/cursor.png");
    sf::Vector2u clickSpot(15, 6);
    sf::Cursor cursor;
    cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), clickSpot);
    window.setMouseCursor(cursor);

    sf::Sprite SpriteUkraine;
    SpriteUkraine.setTexture(TextureUkraine);
    SpriteUkraine.setScale(00.2, 00.2); 
    SpriteUkraine.setPosition(70, 170); 

    sf::Sprite SpriteUkraineAnimation;
    SpriteUkraineAnimation.setTexture(TextureUkraineAnimation);
    SpriteUkraineAnimation.setScale(00.2, 00.2); 
    SpriteUkraineAnimation.setPosition(70, 170); 

    sf::Sprite SpriteRussia;
    SpriteRussia.setTexture(TextureRussia);
    SpriteRussia.setScale(00.2, 00.2); 
    SpriteRussia.setPosition(460, 170); 

    sf::Sprite SpriteRussiaAnimation;
    SpriteRussiaAnimation.setTexture(TextureRussiaAnimation);
    SpriteRussiaAnimation.setScale(00.2, 00.2); 
    SpriteRussiaAnimation.setPosition(460, 170); 

    sf::Sprite SpriteByelorussia;
    SpriteByelorussia.setTexture(TextureByelorussia);
    SpriteByelorussia.setScale(00.2, 00.2); 
    SpriteByelorussia.setPosition(850, 170); 

    sf::Sprite SpriteByelorussiaAnimation;
    SpriteByelorussiaAnimation.setTexture(TextureByelorussiaAnimation);
    SpriteByelorussiaAnimation.setScale(00.2, 00.2); 
    SpriteByelorussiaAnimation.setPosition(850, 170); 

    sf::Sprite SpriteHungary;
    SpriteHungary.setTexture(TextureHungary);
    SpriteHungary.setScale(00.2, 00.2); 
    SpriteHungary.setPosition(1230, 170); 

    sf::Sprite SpriteHungaryAnimation;
    SpriteHungaryAnimation.setTexture(TextureHungaryAnimation);
    SpriteHungaryAnimation.setScale(00.2, 00.2); 
    SpriteHungaryAnimation.setPosition(1230, 170); 

    sf::Sprite SpritePoland;
    SpritePoland.setTexture(TexturePoland);
    SpritePoland.setScale(00.2, 00.2); 
    SpritePoland.setPosition(1620, 170); 

    sf::Sprite SpritePolandAnimation;
    SpritePolandAnimation.setTexture(TexturePolandAnimation);
    SpritePolandAnimation.setScale(00.2, 00.2); 
    SpritePolandAnimation.setPosition(1620, 170); 

    sf::Sprite SpriteGermany;
    SpriteGermany.setTexture(TextureGermany);
    SpriteGermany.setScale(00.2, 00.2); 
    SpriteGermany.setPosition(70, 360); 

    sf::Sprite SpriteGermanyAnimation;
    SpriteGermanyAnimation.setTexture(TextureGermanyAnimation);
    SpriteGermanyAnimation.setScale(00.2, 00.2); 
    SpriteGermanyAnimation.setPosition(70, 360); 

    sf::Sprite SpriteSlovak;
    SpriteSlovak.setTexture(TextureSlovak);
    SpriteSlovak.setScale(00.2, 00.2); 
    SpriteSlovak.setPosition(460, 360); 

    sf::Sprite SpriteSlovakAnimation;
    SpriteSlovakAnimation.setTexture(TextureSlovakAnimation);
    SpriteSlovakAnimation.setScale(00.2, 00.2); 
    SpriteSlovakAnimation.setPosition(460, 360); 

    sf::Sprite SpriteSpanish;
    SpriteSpanish.setTexture(TextureSpanish);
    SpriteSpanish.setScale(00.2, 00.2); 
    SpriteSpanish.setPosition(850, 360); 

    sf::Sprite SpriteSpanishAnimation;
    SpriteSpanishAnimation.setTexture(TextureSpanishAnimation);
    SpriteSpanishAnimation.setScale(00.2, 00.2); 
    SpriteSpanishAnimation.setPosition(850, 360); 

    sf::Sprite SpriteEnglish;
    SpriteEnglish.setTexture(TextureEnglish);
    SpriteEnglish.setScale(00.2, 00.2); 
    SpriteEnglish.setPosition(1230, 360); 

    sf::Sprite SpriteEnglishAnimation;
    SpriteEnglishAnimation.setTexture(TextureEnglishAnimation);
    SpriteEnglishAnimation.setScale(00.2, 00.2); 
    SpriteEnglishAnimation.setPosition(1230, 360); 

    sf::Sprite SpriteCzech;
    SpriteCzech.setTexture(TextureCzech);
    SpriteCzech.setScale(00.2, 00.2); 
    SpriteCzech.setPosition(1620, 360); 

    sf::Sprite SpriteCzechAnimation;
    SpriteCzechAnimation.setTexture(TextureCzechAnimation);
    SpriteCzechAnimation.setScale(00.2, 00.2); 
    SpriteCzechAnimation.setPosition(1620, 360); 

    sf::Sprite SpriteFrench;
    SpriteFrench.setTexture(TextureFrench);
    SpriteFrench.setScale(00.2, 00.2); 
    SpriteFrench.setPosition(70, 550); 

    sf::Sprite SpriteFrenchAnimation;
    SpriteFrenchAnimation.setTexture(TextureFrenchAnimation);
    SpriteFrenchAnimation.setScale(00.2, 00.2); 
    SpriteFrenchAnimation.setPosition(70, 550); 

    sf::Sprite SpriteItalian;
    SpriteItalian.setTexture(TextureItalian);
    SpriteItalian.setScale(00.2, 00.2); 
    SpriteItalian.setPosition(460, 550); 

    sf::Sprite SpriteItalianAnimation;
    SpriteItalianAnimation.setTexture(TextureItalianAnimation);
    SpriteItalianAnimation.setScale(00.2, 00.2); 
    SpriteItalianAnimation.setPosition(460, 550); 

    sf::Sprite SpriteCroatia;
    SpriteCroatia.setTexture(TextureCroatia);
    SpriteCroatia.setScale(00.2, 00.2); 
    SpriteCroatia.setPosition(850, 550); 

    sf::Sprite SpriteCrotiaAnimation;
    SpriteCrotiaAnimation.setTexture(TextureCrotiaAnimation);
    SpriteCrotiaAnimation.setScale(00.2, 00.2); 
    SpriteCrotiaAnimation.setPosition(850, 550); 

    sf::Sprite SpriteFinnish;
    SpriteFinnish.setTexture(TextureFinnish);
    SpriteFinnish.setScale(00.2, 00.2); 
    SpriteFinnish.setPosition(1230, 550); 

    sf::Sprite SpriteFinnishAnimation;
    SpriteFinnishAnimation.setTexture(TextureFinnishAnimation);
    SpriteFinnishAnimation.setScale(00.2, 00.2); 
    SpriteFinnishAnimation.setPosition(1230, 550); 

    sf::Sprite SpriteTurkey;
    SpriteTurkey.setTexture(TextureTurkey);
    SpriteTurkey.setScale(00.2, 00.2); 
    SpriteTurkey.setPosition(1620, 550); 

    sf::Sprite SpriteTurkeyAnimation;
    SpriteTurkeyAnimation.setTexture(TextureTurkeyAnimation);
    SpriteTurkeyAnimation.setScale(00.2, 00.2); 
    SpriteTurkeyAnimation.setPosition(1620, 550); 

    sf::Sprite SpriteKazakh;
    SpriteKazakh.setTexture(TextureKazakh);
    SpriteKazakh.setScale(00.2, 00.2); 
    SpriteKazakh.setPosition(70, 740); 

    sf::Sprite SpriteKazakhAnimation;
    SpriteKazakhAnimation.setTexture(TextureKazakhAnimation);
    SpriteKazakhAnimation.setScale(00.2, 00.2); 
    SpriteKazakhAnimation.setPosition(70, 740); 

    sf::Sprite SpriteNorway;
    SpriteNorway.setTexture(TextureNorway);
    SpriteNorway.setScale(00.2, 00.2); 
    SpriteNorway.setPosition(460, 740); 

    sf::Sprite SpriteNorwayAnimation;
    SpriteNorwayAnimation.setTexture(TextureNorwayAnimation);
    SpriteNorwayAnimation.setScale(00.2, 00.2); 
    SpriteNorwayAnimation.setPosition(460, 740); 

    sf::Sprite SpriteRomania;
    SpriteRomania.setTexture(TextureRomania);
    SpriteRomania.setScale(00.2, 00.2); 
    SpriteRomania.setPosition(850, 740); 

    sf::Sprite SpriteRomaniaAnimation;
    SpriteRomaniaAnimation.setTexture(TextureRomaniaAnimation);
    SpriteRomaniaAnimation.setScale(00.2, 00.2); 
    SpriteRomaniaAnimation.setPosition(850, 740); 

    sf::Sprite SpriteSerbia;
    SpriteSerbia.setTexture(TextureSerbia);
    SpriteSerbia.setScale(00.2, 00.2); 
    SpriteSerbia.setPosition(1230, 740); 

    sf::Sprite SpriteSerbiaAnimation;
    SpriteSerbiaAnimation.setTexture(TextureSerbiaAnimation);
    SpriteSerbiaAnimation.setScale(00.2, 00.2); 
    SpriteSerbiaAnimation.setPosition(1230, 740); 

    sf::Sprite SpriteSweden;
    SpriteSweden.setTexture(TextureSweden);
    SpriteSweden.setScale(00.2, 00.2); 
    SpriteSweden.setPosition(1620, 740); 

    sf::Sprite SpriteSwedenAnimation;
    SpriteSwedenAnimation.setTexture(TextureSwedenAnimation);
    SpriteSwedenAnimation.setScale(00.2, 00.2); 
    SpriteSwedenAnimation.setPosition(1620, 740); 

    sf::Sprite SpriteExit;
    SpriteExit.setTexture(TextureExit);
    SpriteExit.setScale(00.2, 00.2); 
    SpriteExit.setPosition(70, 930); 
    
    sf::Text TextHeading; 
    TextHeading.setFont(FontArimoSemiBold); 
    TextHeading.setString("Language selection"); 
    TextHeading.setCharacterSize(75.6); 
    TextHeading.setFillColor(sf::Color::White);
    TextHeading.setPosition(610, 30); 

    sf::Text TextUkraine; 
    TextUkraine.setFont(FontCalibril); 
    TextUkraine.setString("Ukraine"); 
    TextUkraine.setCharacterSize(35); 
    TextUkraine.setFillColor(sf::Color::White);
    TextUkraine.setPosition(130, 300); 

    sf::Text TextRussia; 
    TextRussia.setFont(FontCalibril); 
    TextRussia.setString("Russia"); 
    TextRussia.setCharacterSize(35); 
    TextRussia.setFillColor(sf::Color::White);
    TextRussia.setPosition(530, 300); 

    sf::Text TextByelorussia; 
    TextByelorussia.setFont(FontCalibril); 
    TextByelorussia.setString("Byelorussia"); 
    TextByelorussia.setCharacterSize(35); 
    TextByelorussia.setFillColor(sf::Color::White);
    TextByelorussia.setPosition(885, 300); 

    sf::Text TextHungary; 
    TextHungary.setFont(FontCalibril); 
    TextHungary.setString("Hungary"); 
    TextHungary.setCharacterSize(35); 
    TextHungary.setFillColor(sf::Color::White);
    TextHungary.setPosition(1290, 300); 

    sf::Text TextPoland; 
    TextPoland.setFont(FontCalibril); 
    TextPoland.setString("Poland"); 
    TextPoland.setCharacterSize(35); 
    TextPoland.setFillColor(sf::Color::White);
    TextPoland.setPosition(1690, 300); 

    sf::Text TextGermany; 
    TextGermany.setFont(FontCalibril); 
    TextGermany.setString("Germany"); 
    TextGermany.setCharacterSize(35); 
    TextGermany.setFillColor(sf::Color::White);
    TextGermany.setPosition(120, 490); 

    sf::Text TextSlovak; 
    TextSlovak.setFont(FontCalibril); 
    TextSlovak.setString("Slovak"); 
    TextSlovak.setCharacterSize(35); 
    TextSlovak.setFillColor(sf::Color::White);
    TextSlovak.setPosition(530, 490); 

    sf::Text TextSpanish; 
    TextSpanish.setFont(FontCalibril); 
    TextSpanish.setString("Spanish"); 
    TextSpanish.setCharacterSize(35); 
    TextSpanish.setFillColor(sf::Color::White);
    TextSpanish.setPosition(910, 490); 

    sf::Text TextEnglish; 
    TextEnglish.setFont(FontCalibril); 
    TextEnglish.setString("English"); 
    TextEnglish.setCharacterSize(35); 
    TextEnglish.setFillColor(sf::Color::White);
    TextEnglish.setPosition(1300, 490); 

    sf::Text TextCzech; 
    TextCzech.setFont(FontCalibril); 
    TextCzech.setString("Czech"); 
    TextCzech.setCharacterSize(35); 
    TextCzech.setFillColor(sf::Color::White);
    TextCzech.setPosition(1690, 490); 

    sf::Text TextFrench; 
    TextFrench.setFont(FontCalibril); 
    TextFrench.setString("French"); 
    TextFrench.setCharacterSize(35); 
    TextFrench.setFillColor(sf::Color::White);
    TextFrench.setPosition(135, 680); 

    sf::Text TextItalian; 
    TextItalian.setFont(FontCalibril); 
    TextItalian.setString("Italian"); 
    TextItalian.setCharacterSize(35); 
    TextItalian.setFillColor(sf::Color::White);
    TextItalian.setPosition(532, 680); 

    sf::Text TextCroatia; 
    TextCroatia.setFont(FontCalibril); 
    TextCroatia.setString("Croatia"); 
    TextCroatia.setCharacterSize(35); 
    TextCroatia.setFillColor(sf::Color::White);
    TextCroatia.setPosition(913, 680); 

    sf::Text TextFinnish; 
    TextFinnish.setFont(FontCalibril); 
    TextFinnish.setString("Finnish"); 
    TextFinnish.setCharacterSize(35); 
    TextFinnish.setFillColor(sf::Color::White);
    TextFinnish.setPosition(1298, 680); 

    sf::Text TextTurkey; 
    TextTurkey.setFont(FontCalibril); 
    TextTurkey.setString("Turkey"); 
    TextTurkey.setCharacterSize(35); 
    TextTurkey.setFillColor(sf::Color::White);
    TextTurkey.setPosition(1690, 680); 

    sf::Text TextKazakh; 
    TextKazakh.setFont(FontCalibril); 
    TextKazakh.setString("Kazakh"); 
    TextKazakh.setCharacterSize(35); 
    TextKazakh.setFillColor(sf::Color::White);
    TextKazakh.setPosition(135, 870); 

    sf::Text TextNorway; 
    TextNorway.setFont(FontCalibril); 
    TextNorway.setString("Norway"); 
    TextNorway.setCharacterSize(35); 
    TextNorway.setFillColor(sf::Color::White);
    TextNorway.setPosition(525, 870); 

    sf::Text TextRomania; 
    TextRomania.setFont(FontCalibril); 
    TextRomania.setString("Romania"); 
    TextRomania.setCharacterSize(35); 
    TextRomania.setFillColor(sf::Color::White);
    TextRomania.setPosition(910, 870); 

    sf::Text TextSerbia; 
    TextSerbia.setFont(FontCalibril); 
    TextSerbia.setString("Serbia"); 
    TextSerbia.setCharacterSize(35); 
    TextSerbia.setFillColor(sf::Color::White);
    TextSerbia.setPosition(1307, 870); 

    sf::Text TextSweden; 
    TextSweden.setFont(FontCalibril); 
    TextSweden.setString("Sweden"); 
    TextSweden.setCharacterSize(35); 
    TextSweden.setFillColor(sf::Color::White);
    TextSweden.setPosition(1685, 870); 

    sf::Text TextExplanatory; 
    TextExplanatory.setFont(FontCalibril); 
    TextExplanatory.setString("To choose the language of the game,click on the flag !"); 
    TextExplanatory.setCharacterSize(70); 
    TextExplanatory.setFillColor(sf::Color::White);
    TextExplanatory.setPosition(370, 940); 

    sf::Text TextExit; 
    TextExit.setFont(FontCalibril); 
    TextExit.setString("Quit the game"); 
    TextExit.setCharacterSize(35); 
    TextExit.setFillColor(sf::Color::White);
    TextExit.setPosition(80, 970); 
    
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
        window.draw(SpriteUkraine);
        window.draw(SpriteRussia);
        window.draw(SpriteByelorussia);
        window.draw(SpriteHungary);
        window.draw(SpritePoland);
        window.draw(SpriteGermany);
        window.draw(SpriteSlovak);
        window.draw(SpriteSpanish);
        window.draw(SpriteEnglish);
        window.draw(SpriteCzech);
        window.draw(SpriteFrench);
        window.draw(SpriteItalian);
        window.draw(SpriteCroatia);
        window.draw(SpriteFinnish);
        window.draw(SpriteTurkey);
        window.draw(SpriteNorway);
        window.draw(SpriteKazakh);
        window.draw(SpriteRomania);
        window.draw(SpriteSerbia);
        window.draw(SpriteSweden);
        window.draw(SpriteExit);
        window.draw(TextHeading);
        window.draw(TextUkraine);
        window.draw(TextRussia);
        window.draw(TextHungary);
        window.draw(TextPoland);
        window.draw(TextGermany);
        window.draw(TextSlovak);
        window.draw(TextSpanish);
        window.draw(TextByelorussia);
        window.draw(TextEnglish);
        window.draw(TextCzech);
        window.draw(TextFrench);
        window.draw(TextItalian);
        window.draw(TextCroatia);
        window.draw(TextFinnish);
        window.draw(TextTurkey);
        window.draw(TextKazakh);
        window.draw(TextNorway);
        window.draw(TextRomania);
        window.draw(TextSerbia);
        window.draw(TextSweden);
        window.draw(TextExplanatory);
        window.draw(TextExit);
        window.setMouseCursor(cursor);

        sf::Vector2i MousePozition = sf::Mouse::getPosition(window);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteUkraine.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteUkraineAnimation);
                window.display(); 
                Sleep(500);
                window.close();
                MenuUkraine();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteRussia.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteRussiaAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuRus();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteByelorussia.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteByelorussiaAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuBel();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteHungary.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteHungaryAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuHun(); 
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpritePoland.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpritePolandAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuPl();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteGermany.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteGermanyAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuGer();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteSlovak.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteSlovakAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuSl();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteSpanish.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteSpanishAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuSp();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteEnglish.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteEnglishAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuEng();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteCzech.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteCzechAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuCzh();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteFrench.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteFrenchAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuFr();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteItalian.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteItalianAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuIt();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteCroatia.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteCrotiaAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuCro();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteFinnish.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteFinnishAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuFin();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteTurkey.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteTurkeyAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuTyr();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteKazakh.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteKazakhAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuKaz();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteNorway.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteNorwayAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuNor();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteRomania.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteRomaniaAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuRom();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteSerbia.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteSerbiaAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuSer();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteSweden.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                music.play();
                window.draw(SpriteSwedenAnimation);
                window.display();
                Sleep(500);
                window.close();
                MenuSw();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (SpriteExit.getGlobalBounds().contains(MousePozition.x, MousePozition.y))
            {
                sf::Sprite SpriteAnimationClick;
                SpriteAnimationClick.setTexture(AnimationClick);
                SpriteAnimationClick.setScale(00.2, 00.2); 
                SpriteAnimationClick.setPosition(70, 930); 
                music.play();
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
