# AC7 VR + HF8 0.8 — instalación y uso

Perfil completo de UEVR con hápticos opcionales para HF8. La instalación es manual, una vez por PC, sin instaladores ni comandos. La sonda incluida envía telemetría local a SimHub, que controla el cojín. No necesitas crear un juego personalizado ni indicar un botón fijo de tu joystick.

## Qué descargar

Desde los archivos de la [versión 0.8](https://github.com/Beren5556/AC7VRDLSS-Downloads/releases/tag/v0.8):

| Uso | Descargas |
| --- | --- |
| VR sin cojín | Solo `Ace7Game-VR.zip` |
| VR con HF8 | `Ace7Game-VR-HF8.zip` y `AC7-HF8-SimHub.zip` |

Los dos ZIP de UEVR incluyen el perfil base de Pande: elige uno. La variante sin HF8 conserva exactamente R37 y no necesita SimHub. La descarga anterior sigue disponible.

Necesitas Windows, ACE COMBAT 7 en Direct3D 11, visor conectado y **UEVR Nightly 01143**, revisión `4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d`. Descarga `UEVR.zip` de [esta versión oficial exacta](https://github.com/praydog/UEVR-nightly/releases/tag/nightly-01143-4ee5c6b6162dee2291fc75f9dfc57667f6d45a2d). Otras nightly no están validadas. Las funciones gráficas requieren una GPU NVIDIA compatible.

Para los hápticos necesitas HF8 alimentado y conectado por USB, y [SimHub](https://www.simhubdash.com/). La prueba física se realizó con **HF8 normal y SimHub 9.12.9 con licencia**. HF8 Pro y otras versiones/ediciones de SimHub no tienen validación física propia de esta entrega.

## 1. Importar el perfil de UEVR

1. Cierra AC7 y UEVR. Cierra también SimHub antes de copiar su definición.
2. Abre el Explorador de archivos y pega `%APPDATA%\UnrealVRMod` en la barra de direcciones.
3. Si existe `Ace7Game`, mueve esa carpeta completa a una ubicación de respaldo fuera de `UnrealVRMod`. Así conservas tus ajustes y evitas mezclar DLL antiguas con la nueva versión.
4. Extrae la nightly indicada en una carpeta propia y abre su inyector.
5. Pulsa **Import Config** y selecciona `Ace7Game-VR-HF8.zip`, o `Ace7Game-VR.zip` si no quieres hápticos. Importa directamente el ZIP; no lo descomprimas en la carpeta del juego ni del inyector.
6. En la variante HF8, comprueba que `%APPDATA%\UnrealVRMod\Ace7Game` contiene `plugins\AC7_Telemetry.dll`, `scripts\HF8_Haptics.lua` y la carpeta `AC7_Haptics`.

El paquete HF8 lleva activada la salida local de telemetría. El perfil de SimHub lleva inicialmente desactivada la salida al cojín: la activarás en el paso 3. Los archivos del renderizador son los mismos de R37.

## 2. Dar de alta AC7 en SimHub

1. Descomprime `AC7-HF8-SimHub.zip` en una carpeta que puedas localizar después.
2. Con SimHub cerrado, pega `%LOCALAPPDATA%\SimHub` en la barra del Explorador.
3. Dentro, crea `ExternalSims`, dentro de ella `Definitions` y dentro `AC7-HF8`, si no existen.
4. Copia el archivo `AC7.simdef` de la descarga a esa última carpeta. La ruta final debe ser `%LOCALAPPDATA%\SimHub\ExternalSims\Definitions\AC7-HF8\AC7.simdef`. Evita una carpeta adicional y comprueba que no termina en `.txt`.
5. Abre SimHub y busca/selecciona **Ace Combat 7 - UEVR Telemetry** en la lista de juegos. No necesitas entrar en Settings → Custom games.

Esta copia utiliza el [mecanismo oficial de definiciones externas de SimHub](https://manual.simhubdash.com/external-sim-integration). No requiere registro de cuenta, tocar el Registro de Windows ni ejecutar comandos. También hay una copia de la definición dentro del perfil UEVR, en `AC7_Haptics\SimHub`.

**Si utilizabas una versión de pruebas:** un registro `.simlink` anterior tiene prioridad sobre la definición copiada. Si aparece la definición antigua o no aparece el juego, cierra SimHub y abre `%LOCALAPPDATA%\SimHub\ExternalSims\Registrations`. Guarda y mueve únicamente `b3a7c5b0-73ea-4e8e-8c1c-3877daf875b3.simlink` a una carpeta de respaldo fuera de Registrations. Conserva la definición nueva en Definitions y reinicia SimHub. No retires registros de otros juegos.

## 3. Importar los efectos y activar el cojín

1. En SimHub abre **ShakeIt Motors → Profiles manager**.
2. Pulsa **Import profile**, selecciona `AC7-HF8.siprofile` de la descarga y carga **AC7 HF8 0.8**.
3. Conserva la configuración de salidas incluida dentro de este perfil. Si aparece una elección entre configuración común o específica del perfil, utiliza la específica para preservar las salidas de otros juegos.
4. Abre **Motors Output**. Busca **ForceFeel Pad / Next Level Racing HF8 Haptic Gaming Pad**. Conecta y enciende el HF8; cierra cualquier otra aplicación que esté controlando el cojín. Activa esa salida.
5. El volumen general inicial es **35%**. Súbelo gradualmente según tu unidad y preferencias. La prueba física de referencia se hizo al 80%, pero no es un valor obligatorio. No confundas el volumen general con los porcentajes individuales de cada efecto.
6. Con AC7 seleccionado, utiliza la selección/asociación de perfiles de SimHub para conservarlo para **Ace Combat 7 - UEVR Telemetry**. No lo asignes a todos los juegos. Si no se selecciona automáticamente, cárgalo manualmente antes de volar.

Se incluyen 14 efectos y ocho motores. Las ganancias y asignaciones proceden de la configuración física aceptada; únicamente se reduce el volumen general de inicio y se desactiva la salida para la primera instalación. Los canales 1/3/5/7 son izquierdos y 0/2/4/6 derechos. Comprueba los motores con las pruebas individuales de SimHub a una intensidad cómoda. Si esas pruebas no vibran, resuelve alimentación, USB y selección de salida antes de probar el juego.

## 4. Volar y ajustar

Abre SimHub, enciende el HF8, inicia AC7 e inyecta con la nightly indicada. Entra en una misión en VR inmersiva y toma el control del avión. Es normal que no haya vibración en el menú, la pausa o las cinemáticas. El modo escritorio/pantalla 2D no sirve para comprobar estos hápticos.

Abre **HF8 Haptics** en UEVR, bajo LuaLoader / Script UI cuando corresponda. **Apply** aplica durante la sesión; **Apply and save** guarda también para el próximo inicio. Espera la confirmación del panel. Una intensidad de cero desactiva ese efecto; **HF8 enabled** activa/desactiva el conjunto.

| Efecto/control | Comportamiento |
| --- | --- |
| Engine minimum / maximum / curve / smoothing | Motor progresivo según acelerador; valores iniciales 18 / 32 / 80 / 250 ms. Cede intensidad ante otros eventos. No mide empuje real. |
| Turns | Vibración en el lado del viraje, intensidad 70. |
| Roll | Recorrido lateral según sentido del alabeo, intensidad 70 y 900 ms. |
| General maneuver | Señal simétrica de movimiento, intensidad 35; no son G medidos. |
| Missiles | Pulso por lanzamiento/consumo de munición, intensidad 90 durante 400 ms. |
| Machine gun | Munición primero; entrada del mando como alternativa automática si falta ese dato. Intensidad 95. |
| Clouds | Traqueteo alterno izquierda/derecha dentro de la nube. Valor 150, pulsos de 75. Textura diseñada, no turbulencia medida. |
| Flares, damage, lightning | Eventos cuando el juego ofrece el dato. El daño no mide la dirección del impacto. |
| Missile warnings | Direccional si hay dirección válida de amenaza; de lo contrario, simétrico. |
| Reverse sides | Invierte la interpretación de los efectos direccionales. |

En UEVR ajustas la respuesta e intensidad de cada sensación; en SimHub, volumen general, activación/ganancia por efecto y motores físicos. Cambia una capa cada vez. Puedes desactivar efectos individualmente sin editar sus fórmulas; estas incluyen protecciones de pausa y pérdida de datos.

La alternativa del cañón lee la configuración DirectInput del juego, identifica el joystick por GUID de producto y utiliza `Flight_Gun`: admite Button1–32 y un modificador entre botones. No cubre teclado, XInput sin sección Joystick del juego, ejes/POV ni expresiones compuestas. Mantener un botón pulsado aproxima el disparo, pero no demuestra que se haya producido.

## Problemas frecuentes

| Síntoma | Comprobación |
| --- | --- |
| AC7 no aparece | Ruta exacta de `AC7.simdef`, reinicio y registro `.simlink` anterior explicado arriba. |
| La prueba de motores no vibra | Alimentación, USB, HF8 activado, volumen y otra aplicación que controle el cojín. |
| La prueba funciona, pero el vuelo no | Juego/perfil correctos en SimHub, nightly exacta, vuelo controlado en VR inmersiva y HF8 enabled en UEVR. DLL, definición y perfil deben ser de esta misma entrega. |
| Sigue sin vibrar | En `%APPDATA%\UnrealVRMod\Ace7Game\AC7_Haptics\AC7_Haptics.ini`, `Enabled` y `OutputEnabled` deben estar a `1`. Reinicia el juego si cambias ese archivo. La telemetría local usa UDP 29777: comprueba conflictos o bloqueo local. No abras ese puerto hacia internet. |
| Todo demasiado tenue | Sube gradualmente el volumen general del perfil SimHub. Si solo falla un efecto, ajusta su intensidad. El techo del motor es deliberadamente menor. |
| Solo el cañón está silencioso | Comprueba los límites de la alternativa automática de entrada; no hay un botón personal fijo. |
| La nube no alterna de lado | Reimporta definición/perfil 0.8 y comprueba sus dos canales independientes. No utilices el perfil alfa antiguo. |
| Deja de vibrar al pausar o perder datos | Es el comportamiento esperado de las protecciones. |
| Cierre al activar DLSS | R37 mantiene una incidencia de identificación de shader/paso en algunos equipos. Prueba a iniciar en TAA con Neural y OFXR apagados y activar DLSS ya en vuelo. Es una alternativa sugerida, no una solución confirmada para todos los casos. Cambiar OFXR exige reiniciar el juego. |

Para ayuda, abre una [incidencia](https://github.com/Beren5556/AC7VRDLSS-Downloads/issues) con versión del mod, nightly, versión de SimHub, modelo HF8, mando y pasos para reproducirla. Retira información personal de los registros que decidas compartir.

## Actualizar o volver atrás

No repitas la instalación en cada vuelo. Antes de actualizar, guarda el perfil UEVR y exporta tus ajustes de SimHub. Actualiza conjuntamente sonda, definición y perfil: un cambio de protocolo puede dejar silencioso un perfil antiguo. Recupera después los ajustes personales que necesites comparando ambas versiones.

Para volver a la variante sin hápticos, cierra las aplicaciones, respalda/mueve todo el perfil AC7 fuera de su carpeta de perfiles e importa `Ace7Game-VR.zip`. Así no queda una DLL háptica antigua cargada. Puedes retirar también la carpeta de definición AC7-HF8 y su perfil de efectos de SimHub, conservando los de otros juegos. También puedes restaurar tu copia completa anterior.

## Términos y alcance

La integración original conserva la licencia MIT y se entrega tal cual, sin garantía, según su texto. No se publican los fuentes compilables de nuestro mod. Se incluyen los Lua necesarios para ejecutar el perfil y los fuentes/materiales obligatorios del OFXR modificado bajo LGPL. Los componentes ajenos conservan sus licencias y créditos. Proyecto comunitario independiente, sin afiliación oficial con Bandai Namco, NVIDIA, SimHub ni Next Level Racing. Consulta los [términos y créditos completos](https://github.com/Beren5556/AC7VRDLSS-Downloads/blob/v0.8/docs/DISTRIBUTION.md).

No se certifican HF8 Pro, otras nightly/juegos ni ganancias de FPS. Proximidad a terreno/objetos, estelas y dirección de disparos recibidos no se presentan como funciones implementadas.
