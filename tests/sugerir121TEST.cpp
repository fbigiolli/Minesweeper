// Tests de la catedra para la función sugerirAutomatico121.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "../definiciones.h"

using namespace std;

// ┌───┬───┬───┬───┬───┐
// │ * │ * │ 1 │ 0 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ 3 │ 3 │ 2 │ 0 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ 1 │ * │ 1 │ 0 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 3 │ 2 │ 1 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ * │ 2 │ * │ 1 │ 0 │
// └───┴───┴───┴───┴───┘
tablero t_vert = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};

// ┌───┬───┬───┬───┬───┐
// │ 1 │ * │ 2 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 2 │ 4 │ 2 │ 2 │
// ├───┼───┼───┼───┼───┤
// │ 1 │ * │ 2 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 3 │ 3 │ 2 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ * │ 2 │ * │ 1 │ 0 │
// └───┴───┴───┴───┴───┘
tablero t_borde = {
        { cVACIA, cMINA,  cVACIA, cMINA,  cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cMINA,  cVACIA, cMINA,  cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};

// ┌───┬───┬───┬───┬───┐
// │ * │ * │ 1 │ 0 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 2 │ 1 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 1 │ 1 │ 0 │ 1 │ * │
// ├───┼───┼───┼───┼───┤
// │ * │ 1 │ 1 │ 2 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 1 │ 2 │ * │ 1 │ 0 │
// └───┴───┴───┴───┴───┘
tablero t_hor = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cMINA  },
        { cMINA,  cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cMINA,  cVACIA, cVACIA },
};

// ┌───┬───┐
// │ 0 │ 0 │
// ├───┼───┤
// │ 0 │ 0 │
// └───┴───┘
tablero t_nohay121 = {
        { cVACIA, cVACIA },
        { cVACIA, cVACIA }
};

TEST(sugerirAutomatico121TEST, sugerenciaValida121Vertical){

    jugadas j = {
            jugada(pos(0, 2), 1), jugada(pos(1, 2), 2), jugada(pos(2, 2), 1), // configuracion 121 vertical
            jugada(pos(1, 4), 0),
            jugada(pos(0, 3), 0), jugada(pos(2, 0), 1),
            jugada(pos(4, 1), 2), jugada(pos(4, 3), 1), jugada(pos(4, 4), 0),
    };

    pos exp_1 = pos(1, 1);
    pos exp_2 = pos(1, 3);
    banderitas b = {
            pos(0, 0),
            pos(0, 1),
    };

    pos sugerido = pos(-1, -1);
    bool resp = sugerirAutomatico121(t_vert, b, j, sugerido);

    EXPECT_TRUE(resp && (sugerido == exp_1 || sugerido == exp_2));
}

TEST(sugerirAutomatico121TEST, sugerenciaValida121Horizontal){

    jugadas j = {
            jugada(pos(3, 2), 1), jugada(pos(3, 3), 2), jugada(pos(3, 4), 1), // configuracion 121 horizontal
            jugada(pos(1, 4), 1),
    };

    pos exp_1 = pos(2, 3);
    pos exp_2 = pos(4, 3);
    banderitas b = {
            pos(0, 0),
            pos(0, 1),
    };

    pos sugerido = pos(-1, -1);
    bool resp = sugerirAutomatico121(t_hor, b, j, sugerido);

    EXPECT_TRUE(resp && (sugerido == exp_1 || sugerido == exp_2));
}

TEST(sugerirAutomatico121TEST, sugerenciaValida121HorizontalConBanderitaSuperpuesta){

    jugadas j = {
            jugada(pos(3, 2), 1), jugada(pos(3, 3), 2), jugada(pos(3, 4), 1), // configuracion 121 horizontal
            jugada(pos(1, 4), 1),
    };

    pos exp_1 = pos(2, 3);
    banderitas b = {
            pos(0, 0),
            pos(4, 3),
    };

    pos sugerido = pos(-1, -1);
    bool resp = sugerirAutomatico121(t_hor, b, j, sugerido);

    EXPECT_TRUE(resp && sugerido == exp_1);
}

TEST(sugerirAutomatico121TEST, sugerenciaValida121VerticalBorde){

    jugadas j = {
            jugada(pos(0, 4), 1), jugada(pos(1, 4), 2), jugada(pos(2, 4), 1), // configuracion 121 vertical
            jugada(pos(0, 3), 0), jugada(pos(2, 0), 1),
            jugada(pos(4, 1), 2),
    };

    pos exp_1 = pos(1, 3);
    banderitas b = {
            pos(0, 0),
            pos(0, 1),
    };

    pos sugerido = pos(-1, -1);
    bool resp = sugerirAutomatico121(t_borde, b, j, sugerido);

    EXPECT_TRUE(resp && sugerido == exp_1);
}

TEST(sugerirAutomatico121TEST, sugerencia2Validas121VerticalBordeConBanderita){

    jugadas j = {
            jugada(pos(0, 4), 1), jugada(pos(1, 4), 2), jugada(pos(2, 4), 1), // configuracion 121 vertical
            jugada(pos(0, 0), 1),  jugada(pos(1, 0), 2), jugada(pos(2, 0), 1), // configuracion 121 vertical pero tiene banderita
            jugada(pos(4, 1), 2),
    };

    pos exp_1 = pos(1, 3);
    banderitas b = {
            pos(1, 1),
    };

    pos sugerido = pos(-1, -1);
    bool resp = sugerirAutomatico121(t_borde, b, j, sugerido);

    EXPECT_TRUE(resp && sugerido == exp_1);
}

TEST(sugerirAutomatico121TEST, noHaySugerenciaPosible){

    jugadas j = {
            jugada(pos(0, 0), 0)
    };

    banderitas b = {};

    pos sugerido = pos(-1, -1);
    bool resp = sugerirAutomatico121(t_borde, b, j, sugerido);

    EXPECT_FALSE(resp); // no hay 121 -> no hay sugerencia
}
