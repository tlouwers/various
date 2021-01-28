
/************************************************************************/
/* Includes                                                             */
/************************************************************************/
#include "DummyClass2.hpp"


/************************************************************************/
/* Public Methods                                                       */
/************************************************************************/
/**
 * \brief   Divide a with b.
 * \param   a   Variable to divide.
 * \param   b   Variable to divide.
 * \returns Division of a with b.
 * \note    If b equals 0 result is 0.
 */
int DummyClass2::Divide(int a, int b) {
    return (b == 0) ? 0 : (a / b);
}
