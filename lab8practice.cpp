 #include <iostream>
#include <string>
#include <vector>

using namespace std;

//////////////////////////////////////////////////////////////////////////
///////////////////////////*Helper Classes*///////////////////////////////
//////////////////////////////////////////////////////////////////////////

/* Collectable Interface */
class Collectable {
  public:
    virtual int getCentury() = 0;

    virtual bool isSuccessful() = 0;

    virtual bool isLegit() = 0;
};

/* Style Class*/
class Style {
  private:
    string name;
    pair<int, int> dominantEra;

  public:
    // Null Constructor
    Style(){};

    // Parameterized Constructor
    Style(string name, int startOfEra, int endOfEra) {
        this->name = name;
        dominantEra = {startOfEra, endOfEra};
    }

    // Getters
    string getName() const { return this->name; }
    pair<int, int> getDominantEra() const { return this->dominantEra; }

    // Methods
    bool equals(Style style) const {
        return this->getName().compare(style.getName()) == 0;
    }
};

/* Artist Class */
class Artist {
  private:
    string name;
    bool deceased;
    int fameScore; // This Score goes on a scale from 0 to 10
    Style primaryStyle;

  public:
    // Null Constructor
    Artist(){};

    // Parameterized Constructor
    Artist(string name, bool deceased, int fameScore, Style primaryStyle) {
        this->name = name;
        this->deceased = deceased;
        this->fameScore = fameScore;
        this->primaryStyle = primaryStyle;
    }

    // Getters
    string getName() const { return name; }
    bool isDeceased() const { return deceased; }
    int getFameScore() const { return fameScore; }
    Style getPrimaryStyle() const { return primaryStyle; }

    // Setters
    void setName(string name) { this->name = name; }
    void setDeceased(bool deceased) { this->deceased = deceased; }
    void setFameScore(int fameScore) { this->fameScore = fameScore; }
    void setPrimaryStyle(Style style) { this->primaryStyle = style; }

    // Methods
    void printArtist() {
        cout << boolalpha;
        cout << "[ Name: " << this->getName() << ", Fame Score: " << this->getFameScore() << ", Primarly Style: " << this->getPrimaryStyle().getName() << ", Is Deceased: " << this->isDeceased() << " ]" << endl;
    }
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////*Art Class*/////////////////////////////////
//////////////////////////////////////////////////////////////////////////
class Art {
  protected:
    string name;
    Artist artist;
    Style style;
    int year;

  public:
    // Null Constructor
    Art(){};

    // Parameterized Constructor
    Art(string name, Artist artist, Style style, int year) {
        this->name = name;
        this->artist = artist;
        this->style = style;
        this->year = year;
    }

    // Getters
    string getName() const { return name; }
    Artist getArtist() const { return artist; }
    Style getStyle() const { return style; }
    int getYear() const { return year; }

    // Setters
    void setName(string name) { this->name = name; }
    void setArtist(Artist artist) { this->artist = artist; }
    void setStyle(Style style) { this->style = style; }
    void setYear(int year) { this->year = year; }

    // Methods
    virtual int appraise() { return 1500; }

    /*
     * Given a vector of Art pieces, return a vector containing only the
     * pieces that are of the given Style
     */
    static vector<Art *> filterCollectionByStyle(const vector<Art *> &personalCollection, Style selected);
};

//////////////////////////////////////////////////////////////////////////
///////////////////////////*Painting Class*///////////////////////////////
//////////////////////////////////////////////////////////////////////////
class Painting : public Art {
  private:
    bool replica;

  public:
    // Null Constructor
    Painting(){};

    // Parameterized Constructor
    Painting(string name, Artist artist, Style style, int year, bool replica) : Art(name, artist, style, year) {
        this->replica = replica;
    }

    // Getters
    bool isReplica() const { return replica; }

    // Setters
    void setReplica(bool isReplica) { this->replica = isReplica; }

    // Methods
    /*
     * Given a vector of Paintings, return the count of how many paintings
     * qualify with the given style and its year is between the given start
     * and end (inclusive).
     */
    static int countPaintings(const vector<Painting *> &collection, Style style, int start, int end);

    int appraise() {
      int price = 0;
      if(this->isReplica() == false && getArtist().getFameScore() > 8) {
        price = appraise() + appraise()*0.66;
      }else if(this->isReplica() == false && getArtist().getFameScore() <= 8 && getArtist().getFameScore() >= 5) {
        price = appraise() + appraise()*0.37;
      }else if(this->isReplica() == false && getArtist().getFameScore() < 5) {
        price = appraise() + appraise()*0.15;
      }else if(this->isReplica() == true) {
        price = appraise();
      }
      return price;
    }
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////*Sculpture Class*///////////////////////////////
//////////////////////////////////////////////////////////////////////////
enum Material {
    WOOD,
    MARBLE,
    WAX,
    PLASTIC,
    METAL
};

class Sculpture : public Art{
  private:

    Material material;

  public:
    // Null Constructor
    Sculpture(){};

    // Parameterized Constructor
    Sculpture(string name, Artist artist, Style style, int year, Material material) : Art(name, artist, style, year) {
        this->material = material;
    }

    // Getters
    Material getMaterial() const { return material; }

    // Setters
    void setMaterial(Material material) { this->material = material; }

    // Methods
    /*
     * Given a vector of Art pieces, return a vector containing only the
     * Sculptures in the original vector. You must use dynamic casting to
     * determine whether an Art piece is a Sculpture or not .
     */
    static vector<Sculpture *> segregateSculptures(const vector<Art *> &collection);
};


int main(){
  //Ex 1
  // Style renaissance("Renaissance", 1300, 1600);
  // Artist leo("Leonardo Da Vinci", true, 10, renaissance);
  // Painting *monaLisa = new Painting("Mona Lisa", leo, renaissance, 1503, false);

  // cout << boolalpha;
  // cout << "************** Exercise 1 **************" << endl;
  // Art *art = dynamic_cast<Art *>(monaLisa);
  // cout << monaLisa->getName() << " is Art: " << (art != NULL) << endl;

  //Ex 2
  // Style cubism("Cubism", 1910, 1920);
  // Style renaissance("Renaissance", 1300, 1600);
  // Artist michael("Michelangelo Buonarroti", true, 10, renaissance);
  // Sculpture *laPieta = new Sculpture("La Pietà", michael, cubism, 1499, Material::MARBLE);
  // cout << boolalpha;
  // cout << "************** Exercise 2 **************" << endl;
  // Art *art = dynamic_cast<Art *>(laPieta);
  // cout << laPieta->getName() << " is Art: " << (art != NULL) << endl;

  //Ex 3
  Style cubism("Cubism", 1910, 1920);
  Style realism("Realism", 1700, 1810);
  Style trippy("Trippy", 1870, 2020);
  Style renaissance("Renaissance", 1300, 1600);

  Artist josefa("Josefa", false, 4, realism);
  Artist paula("Paula A", false, 5, cubism);
  Artist sutano("Sutano Mengano", true, 1, cubism);
  Artist leo("Leonardo Da Vinci", true, 10, renaissance);

  Painting *monaLisa = new Painting("Mona Lisa", leo, renaissance, 1503, false);
  Painting *reloj = new Painting("Reloj", sutano, cubism, 1703, false);
  Painting *butterfly = new Painting("Butterfly", josefa, cubism, 1903, true);
  Painting *flor = new Painting("Flor", paula, trippy, 2006, false);

  cout << boolalpha;
  cout << "************** Exercise 3A **************" << endl;
  cout << butterfly->getName() << " appraise: " << butterfly->appraise() << endl;
  cout << reloj->getName() << " appraise: " << reloj->appraise() << endl;
  cout << flor->getName() << " appraise: " << flor->appraise() << endl;
  cout << monaLisa->getName() << " appraise: " << monaLisa->appraise() << endl;

  return 0;
};