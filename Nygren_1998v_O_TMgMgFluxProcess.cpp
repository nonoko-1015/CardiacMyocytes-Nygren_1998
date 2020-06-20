
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998v_O_TMgMgFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998v_O_TMgMgFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, Mg_i );

  }

  Nygren_1998v_O_TMgMgFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, Mg_i );


  virtual void initialize()
  {
    Process::initialize();

    O_TMgMg  = getVariableReference( "O_TMgMg" ).getVariable();
    O_TMgC  = getVariableReference( "O_TMgC" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( 2000.00*Mg_i*((1.00000-O_TMgC->getValue())-O_TMgMg->getValue())-666.000*O_TMgMg->getValue() );
  }

 protected:

  Variable* O_TMgMg;
  Variable* O_TMgC;

  Real Mg_i;

};

LIBECS_DM_INIT( Nygren_1998v_O_TMgMgFluxProcess, Process );
