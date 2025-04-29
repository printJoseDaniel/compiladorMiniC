prueba10() {
    const int a = 0, b = 0;  // Error léxico: `constant` en lugar de `const`
    var int c;
    
    print("cadena\"abierta\"");
    
    print("Inicio del programa\n");
    
    c = 5 + 2 - 2;
    
    if (a) print("a", "\n");
    else if (b) print("No a y b\n");
    else while (c) {
        print("c =", c, "\n");
        c = c - 2 + 1;
    }
    
    print("Final\n");
}

