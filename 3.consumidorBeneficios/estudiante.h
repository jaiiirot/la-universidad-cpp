struct Estudiante
{
    char name[25];
    char lastname[25];
    char email[60];
    char password[60];
    int creditos;
    int id;
};

Estudiante validarEstudiante(const char* mail, const char* contraseña);

void modificarEstudiante(Estudiante estudiante);