
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998j_Ca_i_cFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998j_Ca_i_cFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998j_Ca_i_cFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    Ca_c  = getVariableReference( "Ca_c" ).getVariable();
    Ca_i  = getVariableReference( "Ca_i" ).getVariable();
    i_B_Ca  = getVariableReference( "i_B_Ca" ).getVariable();
    i_CaP  = getVariableReference( "i_CaP" ).getVariable();
    i_NaCa  = getVariableReference( "i_NaCa" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( ((((i_B_Ca->getValue()+i_CaP->getValue())-2.00000*i_NaCa->getValue())))/(2.00000*F) * N_A * 1.0e-12 );
  }

 protected:

  Variable* Ca_c;
  Variable* Ca_i;
  Variable* i_B_Ca;
  Variable* i_CaP;
  Variable* i_NaCa;

  Real F;

};

LIBECS_DM_INIT( Nygren_1998j_Ca_i_cFluxProcess, Process );
