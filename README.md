# la-universidad-cpp
Trabajo basado a un TP de la UTN.
## Enunciado

Una universidad quiere realizar un sistema de créditos para que sus estudiantes puedan aprovechar los beneficios que ofrece la universidad.

Para poder lograrlo necesita crear 3 módulos:

- **Gestor de estudiantes**: Un sistema donde los estudiantes puedan registrar sus datos e ingresar un código que van a tener que utilizar como clave y se le asigne automáticamente 1000 créditos.
- **Gestor de beneficios**: Un sistema donde la universidad pueda agregar, modificar y eliminar beneficios.
- **Consumidor de beneficios**: Un sistema donde los estudiantes puedan elegir un beneficio y utilizarlo si le alcanzan los puntos.

### **Gestor de estudiantes**

Los estudiantes deben poder registrarse para obtener los beneficios. Cada estudiante debe ingresar su mail y una clave que va a requerir cada vez que quiera consumir beneficios. Una vez registrado, se le asignan 1000 créditos.

El sistema debe guardar los datos de manera permanente en un archivo físico para que pueda ser utilizado por el sistema “Consumidor de beneficios”.

No puede haber dos estudiantes registrados con el mismo mail.

**Bonus point:** Validar que el usuario ingrese un email valido.

### **Gestor de beneficios**

La universidad debe poder gestionar los beneficios que quiere ofrecer. Cada beneficio tiene un nombre y un costo de créditos. 

En el sistema debo poder:

- Listar los beneficios disponibles.
- Modificar el costo de un beneficio
- Agregar más beneficios
- Eliminar beneficios

El sistema debe guardar los datos de manera permanente en un archivo físico para que pueda ser utilizado por el sistema “Consumidor de beneficios”.

### Consumidor **de beneficios**

Un sistema donde los estudiantes puedan consumir los beneficios. El estudiante debe poder ingresar al sistema poniendo su mail y su clave. Una vez que está validado se le muestra el crédito que tiene disponible y lista todos los beneficios disponibles (los que le alcanza el crédito)

El estudiante debe elegir un beneficio y automáticamente se descontará la cantidad de créditos que ese beneficio cueste. 

## Formato de entrega

Debe entregarse una carpeta comprimida que debe tener dentro:

- Un archivo con el código de cada sistema por cada sistema
- Un PDF que tenga:
    - Caratula
    - Lista de participantes del equipo
    - Una explicación donde por cada sistema detalle:
        - Que participantes del equipo estuvieron a cargo de ese sistema
        - Estructuras se crearon y/o utilizaron
        - Patrones algorítmicos utilizados y por qué fueron elegidos
- Link a video de youtube donde muestren como se usa el sistema.

## Fecha de entrega

Enviar por mail antes del 22/09 a las 23:59.

## ¿Cómo apruebo?

- Debo poder hacer un flujo completo en cada sistema
- Deben funcionar todos los sistemas mencionados.
- Aprobar la defensa final oral del trabajo práctico.

## ¿Puedo usar chatgpt?

Se puede usar, pero debemos poder explicar y justificar todo el código, las estructuras usadas y los patrones utilizados en la defensa oral. Ademas, solo podemos usar herramientas que hayamos visto en clase.