
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998j_Ca_dFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998j_Ca_dFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998j_Ca_dFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    Ca_d  = getVariableReference( "Ca_d" ).getVariable();
    Ca_c  = getVariableReference( "Ca_c" ).getVariable();
    i_Ca_L  = getVariableReference( "i_Ca_L" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( -(i_Ca_L->getValue())/(2.00000*F) * N_A * 1.0e-12 );
  }

 protected:

  Variable* Ca_d;
  Variable* Ca_c;
  Variable* i_Ca_L;

  Real F;

};

LIBECS_DM_INIT( Nygren_1998j_Ca_dFluxProcess, Process );
