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
    static vector<Art *> filterCollectionByStyle(const vector<Art *> &personalCollection, Style selected){
      vector<Art *> result;

      for(int i = 0; i < personalCollection.size(); i++) {
        if(personalCollection[i]->getStyle().equals(selected)) {
            result.push_back(personalCollection[i]);
        }
      }
      return result;      
    }
    
};

//////////////////////////////////////////////////////////////////////////
///////////////////////////*Painting Class*///////////////////////////////
//////////////////////////////////////////////////////////////////////////
class Painting : public Art, public Collectable{
  private:
    bool replica;

  public:
    // Null Constructor
    Painting(){};

    // Parameterized Constructor
    Painting(string name, Artist artist, Style style, int year, bool replica) : Art(name, artist, style, year), Collectable() {
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
    static int countPaintings(const vector<Painting *> &collection, Style style, int start, int end) {
      int count = 0;
      for(int i = 0; i < collection.size(); i++) {
        if(collection[i]->getStyle().equals(style) && collection[i]->getYear() >= start && collection[i]->getYear() <= end) {
            count++;
        }
      }
      return count;
    }

    int appraise() {
      int price = 0;
      if(this->isReplica() == false && getArtist().getFameScore() > 8) {
        price = Art::appraise() + Art::appraise()*0.66;
      }else if(this->isReplica() == false && getArtist().getFameScore() <= 8 && getArtist().getFameScore() >= 5) {
        price = Art::appraise() + Art::appraise()*0.37;
      }else if(this->isReplica() == false && getArtist().getFameScore() < 5) {
        price = Art::appraise() + Art::appraise()*0.15;
      }else if(this->isReplica() == true) {
        price = Art::appraise();
      }
      return price;
    }

    int getCentury() {
      int century = (this->getYear()/100) + 1;
      return century;
    }
    bool isSuccessful() {
      if(this->getArtist().getFameScore() > 7 && this->getStyle().getDominantEra().first < this->getYear() && this->getStyle().getDominantEra().second > this->getYear()) {
        return true;
      } else {
        return false;
      }
    }
    bool isLegit() {
      if(this->isReplica() == false) {
        return true;
      } else {
        return false;
      }
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

class Sculpture : public Art, public Collectable{
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
    static vector<Sculpture *> segregateSculptures(const vector<Art *> &collection) {
        vector<Sculpture *> result;

        for (int i = 0; i < collection.size(); i++) {
          Sculpture *sculpture = dynamic_cast<Sculpture *>(collection[i]);
          
          if (sculpture != nullptr) {
            result.push_back(sculpture);
          }
        }

        return result;
    }

    int appraise() {
      int price = 0;
      if(this->getMaterial() == MARBLE && getArtist().getFameScore() >= 5) {
        price = Art::appraise() + Art::appraise()*0.69;
      }else if(this->getMaterial() == METAL && getArtist().getFameScore() > 5) {
        price = Art::appraise() + Art::appraise()*0.45;
      }else if(this->getMaterial() != PLASTIC && getArtist().getFameScore() > 3) {
        price = Art::appraise() + Art::appraise()*0.12;
      }else{
        price = Art::appraise();
      }
      return price;
    }

    int getCentury() {
      int century = (this->getYear()/100) + 1;
      return century;
    }
    bool isSuccessful() {
      if(this->getArtist().getFameScore() > 5 && this->getStyle().getDominantEra().first < this->getYear() && this->getStyle().getDominantEra().second > this->getYear()) {
        return true;
      } else {
        return false;
      }
    }
    bool isLegit() {
      if(this->getMaterial() == MARBLE || this->getMaterial() == WAX || this->getMaterial() == METAL) {
        return true;
      } else {
        return false;
      }
    }
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
  // Style cubism("Cubism", 1910, 1920);
  // Style realism("Realism", 1700, 1810);
  // Style trippy("Trippy", 1870, 2020);
  // Style renaissance("Renaissance", 1300, 1600);

  // Artist josefa("Josefa", false, 4, realism);
  // Artist paula("Paula A", false, 5, cubism);
  // Artist sutano("Sutano Mengano", true, 1, cubism);
  // Artist leo("Leonardo Da Vinci", true, 10, renaissance);

  // Painting *monaLisa = new Painting("Mona Lisa", leo, renaissance, 1503, false);
  // Painting *reloj = new Painting("Reloj", sutano, cubism, 1703, false);
  // Painting *butterfly = new Painting("Butterfly", josefa, cubism, 1903, true);
  // Painting *flor = new Painting("Flor", paula, trippy, 2006, false);

  // cout << boolalpha;
  // cout << "************** Exercise 3A **************" << endl;
  // cout << butterfly->getName() << " appraise: " << butterfly->appraise() << endl;
  // cout << reloj->getName() << " appraise: " << reloj->appraise() << endl;
  // cout << flor->getName() << " appraise: " << flor->appraise() << endl;
  // cout << monaLisa->getName() << " appraise: " << monaLisa->appraise() << endl;

  //Ex 4
  // Style cubism("Cubism", 1910, 1920);
  // Style realism("Realism", 1700, 1810);
  // Style abstract("Abstract", 1900, 2010);
  // Style trippy("Trippy", 1870, 2020);
  // Style renaissance("Renaissance", 1300, 1600);

  // Artist joe("Joe Martin", false, 9, trippy);
  // Artist rudolph("Rudolph Saint", true, 5, cubism);
  // Artist sutano("Sutano Mengano", true, 1, cubism);
  // Artist michael("Michelangelo Buonarroti", true, 10, renaissance);


  // Sculpture *laPieta = new Sculpture("La Pietà", michael, cubism, 1499, Material::MARBLE);
  // Sculpture *hombre = new Sculpture("Hombre", joe, abstract, 2005, Material::METAL);
  // Sculpture *truth = new Sculpture("Truth", sutano, trippy, 1870, Material::PLASTIC);
  // Sculpture *inspiration = new Sculpture("Inspiration", rudolph, renaissance, 1600, Material::WOOD);

  // cout << boolalpha;
  // cout << "************** Exercise 3B **************" << endl;
  // cout << truth->getName() << " appraise: " << truth->appraise() << endl;
  // cout << inspiration->getName() << " appraise: " << inspiration->appraise() << endl;
  // cout << hombre->getName() << " appraise: " << hombre->appraise() << endl;
  // cout << laPieta->getName() << " appraise: " << laPieta->appraise() << endl;

  //Ex 5
  // Style cubism("Cubism", 1910, 1920);
  // Style realism("Realism", 1700, 1810);
  // Style abstract("Abstract", 1900, 2010);
  // Style trippy("Trippy", 1870, 2020);
  // Style renaissance("Renaissance", 1300, 1600);

  // Artist leo("Leonardo Da Vinci", true, 10, renaissance);
  // Artist joe("Joe Martin", false, 9, trippy);
  // Artist josefa("Josefa", false, 4, realism);
  // Artist rudolph("Rudolph Saint", true, 5, cubism);
  // Artist michael("Michelangelo Buonarroti", true, 10, renaissance);

  // Painting *monaLisa = new Painting("Mona Lisa", leo, renaissance, 1503, false);
  // Painting *butterfly = new Painting("Butterfly", josefa, cubism, 1903, true);
  // Painting *aquella = new Painting("Aquella", josefa, realism, 2003, true);

  // Sculpture *laPieta = new Sculpture("La Pietà", michael, cubism, 1499, Material::MARBLE);
  // Sculpture *hombre = new Sculpture("Hombre", joe, abstract, 2005, Material::METAL);
  // Sculpture *inspiration = new Sculpture("Inspiration", rudolph, renaissance, 1600, Material::WOOD);

  // cout << boolalpha;
  // cout << "************** Exercise 4 **************" << endl;
  // vector<Art *> personalCollection = {monaLisa, laPieta, hombre, butterfly, inspiration, aquella};
  // cout << "Quantity before filter: " << personalCollection.size() << endl;
  // cout << "Quantity after filter: " << Art::filterCollectionByStyle(personalCollection, cubism).size() << endl;
  // cout << "Quantity before filter: " << personalCollection.size() << endl;
  // cout << "Quantity after filter: " << Art::filterCollectionByStyle(personalCollection, trippy).size() << endl;
  // personalCollection = {monaLisa, inspiration, inspiration};
  // cout << "Quantity before filter: " << personalCollection.size() << endl;
  // cout << "Quantity after filter: " << Art::filterCollectionByStyle(personalCollection, renaissance).size() << endl;
  // personalCollection = {};
  // cout << "Quantity before filter: " << personalCollection.size() << endl;
  // cout << "Quantity after filter: " << Art::filterCollectionByStyle(personalCollection, realism).size() << endl;

  //Ex 6
  // Style cubism("Cubism", 1910, 1920);
  // Style realism("Realism", 1700, 1810);
  // Style abstract("Abstract", 1900, 2010);
  // Style trippy("Trippy", 1870, 2020);
  // Style renaissance("Renaissance", 1300, 1600);

  // Artist josefa("Josefa", false, 4, realism);
  // Artist paula("Paula A", false, 7, cubism);
  // Artist maria("Maria Pinta", false, 8, abstract);
  // Artist sutano("Sutano Mengano", true, 1, cubism);
  // Artist leo("Leonardo Da Vinci", true, 10, renaissance);

  // Painting *belleza = new Painting("Belleza", maria, abstract, 2010, true);
  // Painting *reloj = new Painting("Reloj", sutano, cubism, 1703, false);
  // Painting *butterfly = new Painting("Butterfly", josefa, cubism, 1903, true);
  // Painting *aquella = new Painting("Aquella", josefa, realism, 2003, true);
  // Painting *flor = new Painting("Flor", paula, trippy, 2006, false);

  // Sculpture *cosa = new Sculpture("Cosa", leo, realism, 1800, Material::WAX);
  // Sculpture *hombre = new Sculpture("Hombre",maria, abstract, 2005, Material::METAL);
  // Sculpture *truth = new Sculpture("Truth", sutano, trippy, 1870, Material::PLASTIC);

  // cout << "************** Exercise 5 **************" << endl;
  // vector<Art *> personalCollection = {reloj, butterfly, aquella};
  // cout << "Quantity before segregation: " << personalCollection.size() << endl;
  // cout << "Quantity after segregation: " << Sculpture::segregateSculptures(personalCollection).size() << endl;
  // personalCollection = {cosa, hombre, truth};
  // cout << "Quantity before segregation: " << personalCollection.size() << endl;
  // cout << "Quantity after segregation: " << Sculpture::segregateSculptures(personalCollection).size() << endl;
  // personalCollection = {flor, cosa, belleza, hombre, truth};
  // cout << "Quantity before segregation: " << personalCollection.size() << endl;
  // cout << "Quantity after segregation: " << Sculpture::segregateSculptures(personalCollection).size() << endl;
  // personalCollection = {};
  // cout << "Quantity before segregation: " << personalCollection.size() << endl;
  // cout << "Quantity after segregation: " << Sculpture::segregateSculptures(personalCollection).size() << endl;

  //Ex7
  // Style realism("Realism", 1700, 1810);
  // Style renaissance("Renaissance", 1300, 1600);
  // Artist josefa("Josefa", false, 5, realism);
  // Artist leo("Leonardo Da Vinci", true, 10, renaissance);

  // Painting *monaLisa = new Painting("Mona Lisa", leo, renaissance, 1503, false);
  // Painting *aquella = new Painting("Aquella", josefa, realism, 2003, true);

  // cout << boolalpha;
  // Collectable *collectable1 = dynamic_cast<Collectable *>(monaLisa);
  // cout << monaLisa->getName() << " is Collectable: " << (collectable1 != NULL) << endl;
  // Art *art3 = dynamic_cast<Art *>(monaLisa);
  // cout << monaLisa->getName() << " is Art: " << (art3 != NULL) << endl;
  // cout << monaLisa->getName() << " Century: " << monaLisa->getCentury() << endl;
  // cout << monaLisa->getName() << " is Successful: " << monaLisa->isSuccessful() << endl;
  // cout << monaLisa->getName() << " is Legit: " << monaLisa->isLegit() << endl;

  // Collectable *collectable2 = dynamic_cast<Collectable *>(aquella);
  // cout << aquella->getName() << " is Collectable: " << (collectable2 != NULL) << endl;
  // Art *art4 = dynamic_cast<Art *>(aquella);
  // cout << aquella->getName() << " is Art: " << (art4 != NULL) << endl;
  // cout << aquella->getName() << " Century: " << aquella->getCentury() << endl;
  // cout << aquella->getName() << " is Successful: " << aquella->isSuccessful() << endl;
  // cout << aquella->getName() << " is Legit: " << aquella->isLegit() << endl;

  //Ex 8
  // Style cubism("Cubism", 1910, 1920);
  // Style realism("Realism", 1700, 1810);
  // Style trippy("Trippy", 1870, 2020);
  // Style renaissance("Renaissance", 1300, 1600);
  
  // Artist sutano("Sutano Mengano", true, 1, cubism);
  // Artist leo("Leonardo Da Vinci", true, 10, renaissance);

  // Sculpture *cosa = new Sculpture("Cosa", leo, realism, 1800, Material::WAX);
  // Sculpture *truth = new Sculpture("Truth", sutano, trippy, 1870, Material::PLASTIC);

  // cout << boolalpha;
  // Collectable *collectable3 = dynamic_cast<Collectable *>(cosa);
  // cout << cosa->getName() << " is Collectable: " << (collectable3 != NULL) << endl;
  // Art *art5 = dynamic_cast<Art *>(cosa);
  // cout << cosa->getName() << " is Art: " << (art5 != NULL) << endl;
  // cout << cosa->getName() << " Century: " << cosa->getCentury() << endl;
  // cout << cosa->getName() << " is Successful: " << cosa->isSuccessful() << endl;
  // cout << cosa->getName() << " is Legit: " << cosa->isLegit() << endl;

  // Collectable *collectable4 = dynamic_cast<Collectable *>(truth);
  // cout << truth->getName() << " is Collectable: " << (collectable4 != NULL) << endl;
  // Art *art6 = dynamic_cast<Art *>(truth);
  // cout << truth->getName() << " is Art: " << (art6 != NULL) << endl;
  // cout << truth->getName() << " Century: " << truth->getCentury() << endl;
  // cout << truth->getName() << " is Successful: " << truth->isSuccessful() << endl;
  // cout << truth->getName() << " is Legit: " << truth->isLegit() << endl;

  //Ex 9
  Style cubism("Cubism", 1910, 1920);
  Style realism("Realism", 1700, 1810);
  Style abstract("Abstract", 1900, 2010);
  Style trippy("Trippy", 1870, 2020);
  Style renaissance("Renaissance", 1300, 1600);

  Artist josefa("Josefa", false, 4, realism);
  Artist paula("Paula A", false, 7, cubism);
  Artist maria("Maria Pinta", false, 8, abstract);
  Artist sutano("Sutano Mengano", true, 1, cubism);
  Artist leo("Leonardo Da Vinci", true, 10, renaissance);

  Painting *monaLisa = new Painting("Mona Lisa", leo, renaissance, 1503, false);
  Painting *belleza = new Painting("Belleza", maria, abstract, 2010, true);
  Painting *reloj = new Painting("Reloj", sutano, cubism, 1703, false);
  Painting *butterfly = new Painting("Butterfly", josefa, cubism, 1903, true);
  Painting *aquella = new Painting("Aquella", josefa, realism, 2003, true);
  Painting *flor = new Painting("Flor", paula, trippy, 2006, false);

  vector<Painting *> paintingCollection = {monaLisa, reloj, belleza, aquella, flor, butterfly};
  cout << "Collection size before: " << paintingCollection.size() << endl;
  cout << "Paintings of " << cubism.getName() << " style between 1700 and 1800: ";
  cout << Painting::countPaintings(paintingCollection, cubism, 1700, 1800) << endl;
  cout << "Collection size after: " << paintingCollection.size() << endl;

  cout << "Collection size before: " << paintingCollection.size() << endl;
  cout << "Paintings of " << trippy.getName() << " style between 1990 and 2005: ";
  cout << Painting::countPaintings(paintingCollection, trippy, 1900, 2005) << endl;
  cout << "Collection size after: " << paintingCollection.size() << endl;

  paintingCollection = {};
  cout << "Collection size before: " << paintingCollection.size() << endl;
  cout << "Paintings of " << realism.getName() << " style between 1890 and 2205: ";
  cout << Painting::countPaintings(paintingCollection, realism, 1890, 2205) << endl;
  cout << "Collection size after: " << paintingCollection.size() << endl;

  return 0;
};