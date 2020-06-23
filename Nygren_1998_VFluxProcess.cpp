
#include "libecs.hpp"
#include "ContinuousProcess.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998_VFluxProcess, ContinuousProcess )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998_VFluxProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, Cm );

  }

  Nygren_1998_VFluxProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, Cm );


  virtual void initialize()
  {
    Process::initialize();
  }

  virtual void fire()
  {
    Real dVdt( 0.0 );

    for( VariableReferenceVector::const_iterator s(
            theZeroVariableReferenceIterator );
         s != thePositiveVariableReferenceIterator; ++s )
    {
        VariableReference const& aVariableReference( *s );
        dVdt += aVariableReference.getVariable()->getValue();
    }

    setFlux( -dVdt / Cm );
  }

 protected:

  Real Cm;

};

LIBECS_DM_INIT( Nygren_1998_VFluxProcess, Process );
