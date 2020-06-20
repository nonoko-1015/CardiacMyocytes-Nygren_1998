
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998j_Ca_up_iFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998j_Ca_up_iFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998j_Ca_up_iFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    Ca_up  = getVariableReference( "Ca_up" ).getVariable();
    Ca_i  = getVariableReference( "Ca_i" ).getVariable();
    i_up  = getVariableReference( "i_up" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( i_up->getValue()/(2.00000*F) * N_A * 1.0e-12 );
  }

 protected:

  Variable* Ca_up;
  Variable* Ca_i;
  Variable* i_up;

  Real F;

};

LIBECS_DM_INIT( Nygren_1998j_Ca_up_iFluxProcess, Process );
