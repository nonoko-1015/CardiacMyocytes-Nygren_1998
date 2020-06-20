
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998j_Ca_iFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998j_Ca_iFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998j_Ca_iFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    Ca_i  = getVariableReference( "Ca_i" ).getVariable();
    dOTCdt  = getVariableReference( "dOTCdt" ).getVariable();
    dOTMgCdt  = getVariableReference( "dOTMgCdt" ).getVariable();
    dOCdt  = getVariableReference( "dOCdt" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( -(0.0800000*dOTCdt->getValue()+0.160000*dOTMgCdt->getValue()+0.0450000*dOCdt->getValue()) * getSuperSystem()->getSizeN_A() / 1000 );
  }

 protected:

  Variable* Ca_i;
  Variable* dOTCdt;
  Variable* dOTMgCdt;
  Variable* dOCdt;

  Real F;

};

LIBECS_DM_INIT( Nygren_1998j_Ca_iFluxProcess, Process );
