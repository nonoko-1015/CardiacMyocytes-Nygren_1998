
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998j_Ca_relFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998j_Ca_relFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998j_Ca_relFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    Ca_rel  = getVariableReference( "Ca_rel" ).getVariable();
    v_O_Calse  = getVariableReference( "v_O_Calse" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( -31.0000 * v_O_Calse->getValue() * getSuperSystem()->getSizeN_A() / 1000 );
  }

 protected:

  Variable* Ca_rel;
  Variable* v_O_Calse;

  Real F;

};

LIBECS_DM_INIT( Nygren_1998j_Ca_relFluxProcess, Process );
