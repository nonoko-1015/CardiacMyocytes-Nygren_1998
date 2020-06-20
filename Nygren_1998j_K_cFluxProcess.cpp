
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998j_K_cFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998j_K_cFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, K_b );
    PROPERTYSLOT_SET_GET( Real, tau_K );

  }

  Nygren_1998j_K_cFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, K_b );
  SIMPLE_SET_GET_METHOD( Real, tau_K );


  virtual void initialize()
  {
    Process::initialize();

    K_c  = getVariableReference( "K_c" ).getVariable();

  }

  virtual void fire()
  {
    setFlux( (K_b-(K_c->getMolarConc()*1000))/tau_K * getSuperSystem()->getSizeN_A() / 1000 );
  }

 protected:

  Variable* K_c;

  Real K_b;
  Real tau_K;

};

LIBECS_DM_INIT( Nygren_1998j_K_cFluxProcess, Process );
