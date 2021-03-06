//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2011 Werner Schweer and others
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2
//  as published by the Free Software Foundation and appearing in
//  the file LICENSE.GPL
//=============================================================================

#include "score.h"
#include "slur.h"
#include "staff.h"
#include "excerpt.h"
#include "chord.h"
#include "rest.h"
#include "keysig.h"
#include "volta.h"
#include "measure.h"
#include "beam.h"
#include "page.h"
#include "segment.h"
#include "ottava.h"
#include "stafftype.h"
#include "text.h"
#include "part.h"
#include "sig.h"
#include "box.h"
#include "dynamic.h"
#include "drumset.h"
#include "style.h"

namespace Ms {

//---------------------------------------------------------
//   StyleVal114
//---------------------------------------------------------

struct StyleVal2 {
      StyleIdx idx;
      StyleVal val;
      };

static const StyleVal2 style114[] = {
      { ST_staffUpperBorder,             StyleVal(Spatium(7.0)) },
      { ST_staffLowerBorder,             StyleVal(Spatium(7.0)) },
      { ST_staffDistance,                StyleVal(Spatium(6.5)) },
      { ST_akkoladeDistance,             StyleVal(Spatium(6.5)) },
      { ST_lyricsDistance,               StyleVal(Spatium(2)) },
      { ST_lyricsMinBottomDistance,      StyleVal(Spatium(2)) },
      { ST_systemFrameDistance,          StyleVal(Spatium(7.0)) },
      { ST_frameSystemDistance,          StyleVal(Spatium(1.0)) },
      { ST_minMeasureWidth,              StyleVal(Spatium(4.0)) },
      { ST_barWidth,                     StyleVal(Spatium(0.16)) },
      { ST_doubleBarWidth,               StyleVal(Spatium(0.16)) },
      { ST_endBarWidth,                  StyleVal(Spatium(0.3)) },
      { ST_doubleBarDistance,            StyleVal(Spatium(0.30)) },
      { ST_endBarDistance,               StyleVal(Spatium(0.30)) },
      { ST_repeatBarTips,                StyleVal(false) },
      { ST_startBarlineSingle,           StyleVal(false) },
      { ST_startBarlineMultiple,         StyleVal(true) },
      { ST_bracketWidth,                 StyleVal(Spatium(0.35)) },
      { ST_bracketDistance,              StyleVal(Spatium(0.25)) },
      { ST_clefLeftMargin,               StyleVal(Spatium(0.5)) },
      { ST_keysigLeftMargin,             StyleVal(Spatium(0.5)) },
      { ST_timesigLeftMargin,            StyleVal(Spatium(0.5)) },
      { ST_clefKeyRightMargin,           StyleVal(Spatium(1.75)) },
      { ST_clefBarlineDistance,          StyleVal(Spatium(0.18)) },
      { ST_stemWidth,                    StyleVal(Spatium(0.13)) },
      { ST_shortenStem,                  StyleVal(true) },
      { ST_shortStemProgression,         StyleVal(Spatium(0.25)) },
      { ST_shortestStem,                 StyleVal(Spatium(2.25)) },
      { ST_beginRepeatLeftMargin,        StyleVal(Spatium(1.0)) },
      { ST_minNoteDistance,              StyleVal(Spatium(0.4)) },
      { ST_barNoteDistance,              StyleVal(Spatium(.6)) },
      { ST_noteBarDistance,              StyleVal(Spatium(1.0)) },
      { ST_measureSpacing,               StyleVal(qreal(1.2)) },
      { ST_staffLineWidth,               StyleVal(Spatium(0.08)) },
      { ST_ledgerLineWidth,              StyleVal(Spatium(0.12)) },
      { ST_akkoladeWidth,                StyleVal(Spatium(1.6)) },
      { ST_accidentalDistance,           StyleVal(Spatium(0.22)) },
      { ST_accidentalNoteDistance,       StyleVal(Spatium(0.22)) },
      { ST_beamWidth,                    StyleVal(Spatium(0.48)) },
      { ST_beamDistance,                 StyleVal(qreal(0.5)) },
      { ST_beamMinLen,                   StyleVal(Spatium(1.25)) },
      { ST_beamMinSlope,                 StyleVal(qreal(0.05)) },
      { ST_beamMaxSlope,                 StyleVal(qreal(0.2)) },
      { ST_maxBeamTicks,                 StyleVal(MScore::division) },
      { ST_dotNoteDistance,              StyleVal(Spatium(0.35)) },
      { ST_dotRestDistance,              StyleVal(Spatium(0.25)) },
      { ST_dotDotDistance,               StyleVal(Spatium(0.5)) },
      { ST_propertyDistanceHead,         StyleVal(Spatium(1.0)) },
      { ST_propertyDistanceStem,         StyleVal(Spatium(0.5)) },
      { ST_propertyDistance,             StyleVal(Spatium(1.0)) },
      { ST_lastSystemFillLimit,          StyleVal(qreal(0.3)) },
      { ST_hairpinHeight,                StyleVal(Spatium(1.2)) },
      { ST_hairpinContHeight,            StyleVal(Spatium(0.5)) },
      { ST_hairpinWidth,                 StyleVal(Spatium(0.13)) },
      { ST_showPageNumber,               StyleVal(true) },
      { ST_showPageNumberOne,            StyleVal(false) },
      { ST_pageNumberOddEven,            StyleVal(true) },
      { ST_showMeasureNumber,            StyleVal(true) },
      { ST_showMeasureNumberOne,         StyleVal(false) },
      { ST_measureNumberInterval,        StyleVal(5) },
      { ST_measureNumberSystem,          StyleVal(true) },
      { ST_measureNumberAllStaffs,       StyleVal(false) },
      { ST_smallNoteMag,                 StyleVal(qreal(0.7)) },
      { ST_graceNoteMag,                 StyleVal(qreal(0.7)) },
      { ST_smallStaffMag,                StyleVal(qreal(0.7)) },
      { ST_smallClefMag,                 StyleVal(qreal(0.8)) },
      { ST_genClef,                      StyleVal(true) },
      { ST_genKeysig,                    StyleVal(true) },
      { ST_genTimesig,                   StyleVal(true) },
      { ST_genCourtesyTimesig,           StyleVal(true) },
      { ST_genCourtesyKeysig,            StyleVal(true) },
      { ST_useStandardNoteNames,         StyleVal(true) },
      { ST_useGermanNoteNames,           StyleVal(false) },
      { ST_useSolfeggioNoteNames,        StyleVal(false) },
      { ST_chordDescriptionFile,         StyleVal(QString("stdchords.xml")) },
      { ST_chordStyle,                   StyleVal(QString("custom")) },
      { ST_chordsXmlFile,                StyleVal(true) },
      { ST_concertPitch,                 StyleVal(false) },
      { ST_createMultiMeasureRests,      StyleVal(false) },
      { ST_minEmptyMeasures,             StyleVal(2) },
      { ST_minMMRestWidth,               StyleVal(Spatium(4)) },
      { ST_hideEmptyStaves,              StyleVal(false) },
      { ST_stemDir1,                     StyleVal(MScore::UP) },
      { ST_stemDir2,                     StyleVal(MScore::DOWN) },
      { ST_stemDir3,                     StyleVal(MScore::UP) },
      { ST_stemDir4,                     StyleVal(MScore::DOWN) },
      { ST_gateTime,                     StyleVal(100) },
      { ST_tenutoGateTime,               StyleVal(100) },
      { ST_staccatoGateTime,             StyleVal(50) },
      { ST_slurGateTime,                 StyleVal(100) },
      { ST_ArpeggioNoteDistance,         StyleVal(Spatium(.5)) },
      { ST_ArpeggioLineWidth,            StyleVal(Spatium(.18)) },
      { ST_ArpeggioHookLen,              StyleVal(Spatium(.8)) },
      { ST_FixMeasureNumbers,            StyleVal(0) },
      { ST_FixMeasureWidth,              StyleVal(false) },
      { ST_keySigNaturals,               StyleVal(NAT_BEFORE) }
      };

//---------------------------------------------------------
//   resolveSymCompatibility
//---------------------------------------------------------

static SymId resolveSymCompatibility(SymId i, QString programVersion)
      {
      if (!programVersion.isEmpty() && programVersion < "1.1")
            i = SymId(i + 5);
      switch(i) {
            case 197:   return pedalPedSym;
            case 191:   return pedalasteriskSym;
            case 193:   return pedaldotSym;
            case 192:   return pedaldashSym;
            case 139:   return trillSym;
            default:    return noSym;
            }
      }

//---------------------------------------------------------
//   Staff::read114
//---------------------------------------------------------

void Staff::read114(XmlReader& e, ClefList& _clefList)
      {
      while (e.readNextStartElement()) {
            const QStringRef& tag(e.name());
            if (tag == "lines")
                  setLines(e.readInt());
            else if (tag == "small")
                  setSmall(e.readInt());
            else if (tag == "invisible")
                  setInvisible(e.readInt());
            else if (tag == "slashStyle")
                  e.skipCurrentElement();
            else if (tag == "cleflist")
                  _clefList.read(e, _score);
            else if (tag == "keylist")
                  _keymap.read(e, _score);
            else if (tag == "bracket") {
                  BracketItem b;
                  b._bracket = BracketType(e.intAttribute("type", -1));
                  b._bracketSpan = e.intAttribute("span", 0);
                  _brackets.append(b);
                  e.readNext();
                  }
            else if (tag == "barLineSpan")
                  _barLineSpan = e.readInt();
            else
                  e.unknown();
            }
      }

//---------------------------------------------------------
//   Part::read114
//---------------------------------------------------------

void Part::read114(XmlReader& e)
      {
      int rstaff = 0;
      while (e.readNextStartElement()) {
            const QStringRef& tag(e.name());
            if (tag == "Staff") {
                  Staff* staff = new Staff(_score, this, rstaff);
                  _score->staves().push_back(staff);
                  _staves.push_back(staff);
                  ClefList* cl = new ClefList;
                  e.clefListList().append(cl);
                  staff->read114(e, *cl);
                  ++rstaff;
                  }
            else if (tag == "Instrument") {
                  instr(0)->read(e);
                  Drumset* d = instr(0)->drumset();
                  Staff*   st = staff(0);
                  if (d && st && st->lines() != 5) {
                        int n = 0;
                        if (st->lines() == 1)
                              n = 4;
                        for (int  i = 0; i < DRUM_INSTRUMENTS; ++i)
                              d->drum(i).line -= n;
                        }
                  }
            else if (tag == "name") {
                  Text* t = new Text(score());
                  t->read(e);
                  instr(0)->setLongName(t->getFragment());
                  delete t;
                  }
            else if (tag == "shortName") {
                  Text* t = new Text(score());
                  t->read(e);
                  instr(0)->setShortName(t->getFragment());
                  delete t;
                  }
            else if (tag == "trackName")
                  _partName = e.readElementText();
            else if (tag == "show")
                  _show = e.readInt();
            else
                  e.unknown();
            }
      if (_partName.isEmpty())
            _partName = instr(0)->trackName();

      if (instr(0)->useDrumset()) {
            foreach(Staff* staff, _staves) {
                  int lines = staff->lines();
                  staff->setStaffType(score()->staffType(PERCUSSION_STAFF_TYPE));
                  staff->setLines(lines);
                  }
            }
      }

//---------------------------------------------------------
//   read114
//    import old version 1.2 files
//---------------------------------------------------------

Score::FileError Score::read114(XmlReader& e)
      {
      if (parentScore())
            setMscVersion(parentScore()->mscVersion());

      for (unsigned int i = 0; i < sizeof(style114)/sizeof(*style114); ++i)
            style()->set(style114[i].idx, style114[i].val);

      while (e.readNextStartElement()) {
            e.setTrack(-1);
            const QStringRef& tag(e.name());
            if (tag == "Staff")
                  readStaff(e);
            else if (tag == "KeySig") {
                  KeySig* ks = new KeySig(this);
                  ks->read(e);
                  customKeysigs.append(ks);
                  }
            else if (tag == "siglist")
                  _sigmap->read(e, _fileDivision);
            else if (tag == "programVersion") {
                  _mscoreVersion = e.readElementText();
                  parseVersion(_mscoreVersion);
                  }
            else if (tag == "programRevision")
                  _mscoreRevision = e.readInt();
            else if (tag == "Mag"
               || tag == "MagIdx"
               || tag == "xoff"
               || tag == "tempolist"
               || tag == "Symbols"
               || tag == "cursorTrack"
               || tag == "yoff")
                  e.skipCurrentElement();       // obsolete
            else if (tag == "playMode")
                  _playMode = PlayMode(e.readInt());
            else if (tag == "SyntiSettings")
                  _synthesizerState.read(e);
            else if (tag == "Spatium")
                  _style.setSpatium (e.readDouble() * MScore::DPMM);
            else if (tag == "Division")
                  _fileDivision = e.readInt();
            else if (tag == "showInvisible")
                  _showInvisible = e.readInt();
            else if (tag == "showFrames")
                  _showFrames = e.readInt();
            else if (tag == "showMargins")
                  _showPageborders = e.readInt();
            else if (tag == "Style") {
                  qreal sp = _style.spatium();
                  _style.load(e);
                  if (_layoutMode == LayoutFloat) {
                        // style should not change spatium in
                        // float mode
                        _style.setSpatium(sp);
                        }
                  }
            else if (tag == "TextStyle") {
                  TextStyle s;
                  s.read(e);

                  // Change 1.2 Poet to Lyricist
                  if (s.name() == "Poet")
                        s.setName("Lyricist");
                  if (s.name() == "Lyrics odd lines" || s.name() == "Lyrics even lines")
                        s.setAlign((s.align() & ~ ALIGN_VMASK) | Align(ALIGN_BASELINE));

                  _style.setTextStyle(s);
                  }
            else if (tag == "page-layout") {
                  if (_layoutMode != LayoutFloat && _layoutMode != LayoutSystem) {
                        PageFormat pf;
                        pf.copy(*pageFormat());
                        pf.read(e, this);
                        setPageFormat(pf);
                        }
                  else
                        e.skipCurrentElement();
                  }
            else if (tag == "copyright" || tag == "rights") {
                  Text* text = new Text(this);
                  text->read(e);
                  setMetaTag("copyright", text->text());
                  delete text;
                  }
            else if (tag == "movement-number")
                  setMetaTag("movementNumber", e.readElementText());
            else if (tag == "movement-title")
                  setMetaTag("movementTitle", e.readElementText());
            else if (tag == "work-number")
                  setMetaTag("workNumber", e.readElementText());
            else if (tag == "work-title")
                  setMetaTag("workTitle", e.readElementText());
            else if (tag == "source")
                  setMetaTag("source", e.readElementText());
            else if (tag == "metaTag") {
                  QString name = e.attribute("name");
                  setMetaTag(name, e.readElementText());
                  }
            else if (tag == "Part") {
                  Part* part = new Part(this);
                  part->read114(e);
                  _parts.push_back(part);
                  }
            else if (tag == "Slur") {
                  Slur* slur = new Slur(this);
                  slur->read(e);
                  addSpanner(slur);
                  }
            else if ((tag == "HairPin")
                || (tag == "Ottava")
                || (tag == "TextLine")
                || (tag == "Volta")
                || (tag == "Trill")
                || (tag == "Pedal")) {
                  Spanner* s = static_cast<Spanner*>(Element::name2Element(tag, this));
                  s->read(e);
                  if (s->track() == -1)
                        s->setTrack(e.track());
                  else
                        e.setTrack(s->track());       // update current track
                  if (s->tick() == -1)
                        s->setTick(e.tick());
                  else
                        e.setTick(s->tick());      // update current tick
                  if (s->tickLen() == -1) {
                        delete s;
                        qDebug("invalid spanner %s tickLen: %d\n",
                           s->name(), s->tickLen());
                        }
                  else
                        addSpanner(s);
                  }
            else if (tag == "Excerpt") {
                  Excerpt* ex = new Excerpt(this);
                  ex->read(e);
                  _excerpts.append(ex);
                  }
            else if (tag == "Beam") {
                  Beam* beam = new Beam(this);
                  beam->read(e);
                  beam->setParent(0);
                  // _beams.append(beam);
                  }
            else if (tag == "name")
                  setName(e.readElementText());
            else
                  e.unknown();
            }

      if (e.error() != QXmlStreamReader::NoError)
            return FILE_BAD_FORMAT;

      int n = nstaves();
      for (int idx = 0; idx < n; ++idx) {
            Staff* s = _staves[idx];
            int track = idx * VOICES;

            // check barLineSpan
            if (s->barLineSpan() > (n - idx)) {
                  qDebug("read114: invalid bar line span %d (max %d)",
                     s->barLineSpan(), n - idx);
                  s->setBarLineSpan(n - idx);
                  }

            ClefList* cl = e.clefListList().at(idx);
            for (auto i = cl->constBegin(); i != cl->constEnd(); ++i) {
                  int tick = i.key();
                  ClefType clefId = i.value()._concertClef;
                  Measure* m = tick2measure(tick);
                  if (!m)
                        continue;
                  if ((tick == m->tick()) && m->prevMeasure())
                        m = m->prevMeasure();
                  Segment* seg = m->getSegment(Segment::SegClef, tick);
                  if (seg->element(track))
                        static_cast<Clef*>(seg->element(track))->setGenerated(false);
                  else {
                        Clef* clef = new Clef(this);
                        clef->setClefType(clefId);
                        clef->setTrack(track);
                        clef->setParent(seg);
                        clef->setGenerated(false);
                        seg->add(clef);
                        }
                  }

            KeyList* km = s->keymap();
            for (auto i = km->begin(); i != km->end(); ++i) {
                  int tick = i->first;
                  if (tick < 0) {
                        qDebug("read114: Key tick %d", tick);
                        continue;
                        }
                  KeySigEvent ke = i->second;
                  Measure* m = tick2measure(tick);
                  if(!m) //empty score
                        break;
                  Segment* seg = m->getSegment(Segment::SegKeySig, tick);
                  if (seg->element(track))
                        static_cast<KeySig*>(seg->element(track))->setGenerated(false);
                  else {
                        KeySig* ks = keySigFactory(ke);
                        if (ks) {
                              ks->setParent(seg);
                              ks->setTrack(track);
                              ks->setGenerated(false);
                              seg->add(ks);
                              }
                        }
                  }
            }
      qDeleteAll(e.clefListList());

      for (std::pair<int,Spanner*> p : spanner()) {
            Spanner* s = p.second;
            if (s->type() == Element::OTTAVA
               || (s->type() == Element::TEXTLINE)
               || (s->type() == Element::VOLTA)
               || (s->type() == Element::PEDAL))
                  {
                  TextLine* tl = static_cast<TextLine*>(s);
                  tl->setBeginSymbol(resolveSymCompatibility(tl->beginSymbol(), mscoreVersion()));
                  tl->setContinueSymbol(resolveSymCompatibility(tl->continueSymbol(), mscoreVersion()));
                  tl->setEndSymbol(resolveSymCompatibility(tl->endSymbol(), mscoreVersion()));
                  }

            if (s->type() != Element::SLUR) {
                  if (s->type() == Element::VOLTA) {
                        Volta* volta = static_cast<Volta*>(s);
                        volta->setAnchor(Spanner::ANCHOR_MEASURE);
                        }
                  }

            if (s->type() == Element::OTTAVA) {
                  // fix ottava position
                  Ottava* ottava = static_cast<Ottava*>(s);
                  int n = ottava->spannerSegments().size();
                  for (int i = 0; i < n; ++i) {
                        LineSegment* seg = ottava->segmentAt(i);
                        if (!seg->userOff().isNull())
                              seg->setUserYoffset(seg->userOff().y() - styleP(ST_ottavaY));
                        }
                  ottava->staff()->updateOttava(ottava);
                  }
            }

      connectTies();

      //
      // remove "middle beam" flags from first ChordRest in
      // measure
      //
      for (Measure* m = firstMeasure(); m; m = m->nextMeasure()) {
            int tracks = nstaves() * VOICES;
            for (int track = 0; track < tracks; ++track) {
                  for (Segment* s = m->first(); s; s = s->next()) {
                        if (s->segmentType() != Segment::SegChordRest)
                              continue;
                        ChordRest* cr = static_cast<ChordRest*>(s->element(track));
                        if (cr) {
                              switch(cr->beamMode()) {
                                    case BeamMode::AUTO:
                                    case BeamMode::BEGIN:
                                    case BeamMode::END:
                                    case BeamMode::NONE:
                                          break;
                                    case BeamMode::MID:
                                    case BeamMode::BEGIN32:
                                    case BeamMode::BEGIN64:
                                          cr->setBeamMode(BeamMode::BEGIN);
                                          break;
                                    case BeamMode::INVALID:
                                          if (cr->type() == Element::CHORD)
                                                cr->setBeamMode(BeamMode::AUTO);
                                          else
                                                cr->setBeamMode(BeamMode::NONE);
                                          break;
                                    }
                              break;
                              }
                        }
                  }
            }
      for (MeasureBase* mb = _measures.first(); mb; mb = mb->next()) {
            if (mb->type() == Element::VBOX) {
                  Box* b  = static_cast<Box*>(mb);
                  qreal y = point(styleS(ST_staffUpperBorder));
                  b->setBottomGap(y);
                  }
            }

      _fileDivision = MScore::division;

      //
      //    sanity check for barLineSpan
      //
      foreach(Staff* staff, _staves) {
            int barLineSpan = staff->barLineSpan();
            int idx = staffIdx(staff);
            int n = nstaves();
            if (idx + barLineSpan > n) {
                  qDebug("bad span: idx %d  span %d staves %d", idx, barLineSpan, n);
                  staff->setBarLineSpan(n - idx);
                  }
            }

      // adjust some styles
      if (styleS(ST_lyricsDistance).val() == MScore::baseStyle()->valueS(ST_lyricsDistance).val())
            style()->set(ST_lyricsDistance, Spatium(2.0));
      if (styleS(ST_voltaY).val() == MScore::baseStyle()->valueS(ST_voltaY).val())
            style()->set(ST_voltaY, Spatium(-2.0));
      if (styleB(ST_hideEmptyStaves) == true) // http://musescore.org/en/node/16228
            style()->set(ST_dontHideStavesInFirstSystem, false);
      if (styleB(ST_useGermanNoteNames))
            style()->set(ST_useStandardNoteNames, false);

      _showOmr = false;

      // create excerpts
      foreach (Excerpt* excerpt, _excerpts) {
            if (excerpt->parts().isEmpty()) {         // ignore empty parts
                  _excerpts.removeOne(excerpt);
                  continue;
                  }
            Score* nscore = Ms::createExcerpt(excerpt->parts());
            if (nscore) {
                  nscore->setParentScore(this);
                  nscore->setName(excerpt->title());
                  nscore->rebuildMidiMapping();
                  nscore->updateChannel();
                  nscore->addLayoutFlags(LAYOUT_FIX_PITCH_VELO);
                  nscore->doLayout();
                  excerpt->setScore(nscore);
                  }
            }

//      _mscVersion = MSCVERSION;     // for later drag & drop usage
      fixTicks();
      renumberMeasures();
      rebuildMidiMapping();
      updateChannel();
      updateNotes();    // only for parts needed?

      doLayout();

      //
      // move some elements
      //
      for (Segment* s = firstSegment(); s; s = s->next1()) {
            foreach (Element* e, s->annotations()) {
                  if (e->type() == Element::TEMPO_TEXT) {
                        // reparent from measure to segment
                        e->setUserOff(QPointF(e->userOff().x() - s->pos().x(),
                           e->userOff().y()));
                        }
                  }
            }

      return FILE_NO_ERROR;
      }

}

