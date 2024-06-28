#ifndef AREA_H
#define AREA_H


class Area
{
public:
    // CONSTRUCTOR
    Area();
    Area(int idArea, std::string nombre);

    // GETTERS
    int getIdArea();
    std::string getNombre();

    // SETTERS
    void setIdArea(int idArea);
    void setNombre(std::string nombre);

private:
    int _idArea;
    char _nombre[20];
    //bool _estado;
};
#endif // AREA_H
