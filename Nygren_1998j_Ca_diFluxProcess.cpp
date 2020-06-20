
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998j_Ca_diFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998j_Ca_diFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998j_Ca_diFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    Ca_i  = getVariableReference( "Ca_i" ).getVariable();
    Ca_d  = getVariableReference( "Ca_d" ).getVariable();
    i_di  = getVariableReference( "i_di" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (i_di->getValue())/(2.00000*F) * N_A * 1.0e-12 );
  }

 protected:

  Variable* Ca_i;
  Variable* Ca_d;
  Variable* i_di;

  Real F;

};

LIBECS_DM_INIT( Nygren_1998j_Ca_diFluxProcess, Process );
