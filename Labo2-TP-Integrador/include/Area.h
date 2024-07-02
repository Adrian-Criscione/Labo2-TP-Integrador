#ifndef AREA_H
#define AREA_H


class Area
{
public:
    // CONSTRUCTOR
    Area();
    Area(int idArea, std::string nombre, bool estado);

    // GETTERS
    int getIdArea();
    std::string getNombre();
    std::string getNombreID();
    std::string toString();
    bool getEstado();

    // SETTERS
    void setIdArea(int idArea);
    void setNombre(std::string nombre);
    void setEstado(bool estado);

private:
    int _idArea;
    char _nombre[20];
    bool _estado;
};
#endif // AREA_H
