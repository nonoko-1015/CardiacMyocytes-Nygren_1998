
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998j_Ca_rel_upFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998j_Ca_rel_upFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998j_Ca_rel_upFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    Ca_rel  = getVariableReference( "Ca_rel" ).getVariable();
    Ca_up  = getVariableReference( "Ca_up" ).getVariable();
    i_tr  = getVariableReference( "i_tr" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( i_tr->getValue()/(2.00000*F) * N_A * 1.0e-12 );
  }

 protected:

  Variable* Ca_rel;
  Variable* Ca_up;
  Variable* i_tr;

  Real F;

};

LIBECS_DM_INIT( Nygren_1998j_Ca_rel_upFluxProcess, Process );
