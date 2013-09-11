/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libkeynote project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef KN2TOKEN_H_INCLUDED
#define KN2TOKEN_H_INCLUDED

#include "KNToken.h"

namespace libkeynote
{

namespace KN2Token
{

enum
{
  INVALID_TOKEN = 0,

  // namespaces
  NS_URI_KEY,
  NS_URI_SF,
  NS_URI_SFA,
  NS_URI_XSI,
  xmlns,

  // elements
  alignment,
  alignment_guide,
  alpha_mask_path,
  angle_gradient,
  animationAuto,
  animationAutoPlay,
  animationDelay,
  animationDelayAutmaticAfter,
  animationDelayAutomaticWith,
  animationDuration,
  animationEndOffset,
  animationInterchunkAuto,
  animationInterchunkDelay,
  animationStartOffset,
  animationTimingReferent,
  animationType,
  anon_styles,
  array,
  array_ref,
  atsuFontFeatures,
  authors,
  baselineShift,
  bezier,
  bezier_path,
  bezier_ref,
  BGBuildChunk,
  BGBuildDurationProperty,
  BGShowUIStateActiveDrawable,
  BGShowUIStateActiveSlide,
  BGShowUIStateCanvasOrigin,
  BGShowUIStateCanvasZoom,
  BGShowUIStateMasterNavigatorHeight,
  BGShowUIStateMotionPathSelection,
  BGShowUIStateNavigatorThumbnailWidth,
  BGShowUIStateNavigatorWidth,
  BGShowUIStateNotesHeight,
  BGShowUIStateNotesVisible,
  BGShowUIStateRulersVisible,
  BGShowUIStateSelectedDrawables,
  BGShowUIStateSelectedHeadlines,
  BGShowUIStateSelectedMasters,
  BGShowUIStateSelectedSlides,
  BGShowUIStateViewLayout,
  BGShowUIStateWindowSize,
  binary,
  binary_ref,
  blendMode,
  body_placeholder,
  body_placeholder_ref,
  bodyPlaceholderVisibility,
  bold,
  br,
  build,
  build_chunk,
  build_chunks,
  bulletListStyle,
  bullets,
  calc_engine,
  calc_engine_entities,
  calculation_engine,
  callout2_path,
  capitalization,
  cell_comment_mapping,
  cell_precedents,
  cell_storage,
  cell_style,
  cell_style_ref,
  cell_text,
  characterstyle,
  characterstyle_ref,
  chart_column_names,
  chart_containingviewport,
  chart_data,
  chart_info,
  chart_legendInfo,
  chart_model,
  chart_row_names,
  chart_series_style,
  chart_series_style_ref,
  chart_style,
  chart_style_ref,
  color,
  column,
  columns,
  com_apple_iWork_Keynote_BCDissolveByCharacter_slowFade,
  com_apple_iWork_Keynote_KLNBCConvergence_height,
  com_apple_iWork_Keynote_KLNBouncy_order,
  com_apple_iWork_Keynote_KLNComet_color,
  com_apple_iWork_Keynote_KLNSparkle_color,
  components,
  connection_path,
  connection_style,
  content,
  content_size,
  core_image_filter_descriptor,
  core_image_filter_descriptor_ref,
  core_image_filter_info,
  crbr,
  crop_geometry,
  custom_space_color,
  data,
  datasource,
  date_format,
  date_format_ref,
  decimal_number,
  decimalTab,
  defaultTabStops,
  dependency_tracker,
  dependents,
  dictionary,
  direction,
  drawables,
  dropCap,
  dummy_body_headline,
  duration_format,
  duration_format_ref,
  editable_bezier_path,
  effect,
  effectColor,
  end_point,
  error_warning_mapping,
  events,
  extent,
  external_text_wrap,
  externalTextWrap,
  fill,
  filtered_image,
  filtered_image_ref,
  filters,
  filterset,
  filterspec,
  firstLineIndent,
  firstTopicNumber,
  followingLayoutStyle,
  followingParagraphStyle,
  fontColor,
  fontName,
  fontSize,
  frame,
  geometry,
  gradient_stop,
  graphic_style,
  graphic_style_ref,
  grid,
  grid_column,
  grid_row,
  group,
  guides,
  head,
  headline,
  headLineEnd,
  headlineIndent,
  headlineParagraphStyle,
  headline_style,
  headOffset,
  hidden,
  horizontal_gridline_styles,
  hyphenate,
  image,
  image_media,
  image_ref,
  info_ref,
  inputAngle,
  inputColor,
  inputDistance,
  inputOpacity,
  inputRadius,
  intratopicbr,
  italic,
  kBGShowObjectElements,
  keepLinesTogether,
  keepWithNext,
  kerning,
  key,
  keywords,
  labelCharacterStyle1,
  labelCharacterStyle2,
  labelCharacterStyle3,
  labelCharacterStyle4,
  labelCharacterStyle5,
  labelCharacterStyle6,
  labelCharacterStyle7,
  labelCharacterStyle8,
  labelCharacterStyle9,
  language,
  layer,
  layer_ref,
  layers,
  layout,
  layoutContinuous,
  layoutMargins,
  layoutParagraphStyle,
  layoutstyle,
  layoutStyle,
  layoutstyle_ref,
  leftIndent,
  legend_chartInfo_ref,
  ligatures,
  line,
  line_end,
  linespacing,
  lineSpacing,
  linespacing_ref,
  link,
  link_ref,
  listLabelGeometries,
  list_label_geometry,
  list_label_geometry_ref,
  listLabelIndents,
  list_label_typeinfo,
  list_label_typeinfo_ref,
  listLabelTypes,
  list_level,
  listLevels,
  liststyle,
  listStyle,
  liststyle_ref,
  listTextIndents,
  lnbr,
  main_movie,
  main_movie_data_description,
  masking_shape_path_source,
  master_order,
  master_ref,
  master_slide,
  master_slide_ref,
  master_slides,
  media,
  metadata,
  minimumHorizontalInset,
  movie_media,
  mutable_array,
  mutable_array_ref,
  mutable_dictionary,
  naturalSize,
  notes,
  null,
  number,
  number_format,
  number_format_ref,
  object_placeholder,
  objectPlaceholderVisibility,
  opacity,
  original_bounds,
  other_datas,
  outline,
  outlineColor,
  outlineLevel,
  outlineStyleType,
  overrides,
  p,
  padding,
  padding_ref,
  page,
  pageBreakBefore,
  pair,
  paragraphBorders,
  paragraphBorderType,
  paragraphFill,
  paragraphRuleOffset,
  paragraphRuleWidth,
  paragraphStroke,
  paragraphstyle,
  paragraphstyle_ref,
  parent_build_ref,
  parent_ref,
  path,
  pattern,
  pattern_ref,
  pk_dict,
  placeholder_size,
  placeholder_style,
  placeholder_style_ref,
  point,
  point_path,
  position,
  poster_image,
  presentation,
  profile_data,
  profile_data_ref,
  property_map,
  proxy_master_layer,
  range_precedents,
  rect,
  reflect,
  reflection,
  rightIndent,
  rows,
  scalar_path,
  self_contained_movie,
  Series_0,
  Series_1,
  Series_2,
  Series_3,
  Series_4,
  Series_5,
  set,
  SFC2DAntialiasingModeProperty,
  SFC2DAreaDataPointFillProperty,
  SFC2DAreaDataPointStrokeProperty,
  SFC2DAreaDataPointSymbolProperty,
  SFC2DAreaFillProperty,
  SFC2DAreaShadowProperty,
  SFC2DAreaStrokeProperty,
  SFC2DAreaUseSeriesFillForDataPointFillProperty,
  SFC2DAreaUseStrokeColorForDataPointFillProperty,
  SFC2DBarFillProperty,
  SFC2DBarShadowProperty,
  SFC2DBarStrokeProperty,
  SFC2DBottomBorderOpacityProperty,
  SFC2DBottomBorderShadowProperty,
  SFC2DBottomBorderStrokeProperty,
  SFC2DCategoryDirectionGridLineOpacityProperty,
  SFC2DCategoryDirectionGridLineShadowProperty,
  SFC2DCategoryDirectionGridLineStrokeProperty,
  SFC2DCategoryDirectionMinorGridLineIntervalProperty,
  SFC2DCategoryDirectionMinorGridLineOpacityProperty,
  SFC2DCategoryDirectionMinorGridLineShadowProperty,
  SFC2DCategoryDirectionMinorGridLineStrokeProperty,
  SFC2DChartBackgroundFillProperty,
  SFC2DChartBackgroundOpacityProperty,
  SFC2DColumnFillProperty,
  SFC2DCombineLayersProperty,
  SFC2DLeftBorderOpacityProperty,
  SFC2DLeftBorderShadowProperty,
  SFC2DLeftBorderStrokeProperty,
  SFC2DLineConnectedPointsProperty,
  SFC2DLineDataPointFillProperty,
  SFC2DLineDataPointStrokeProperty,
  SFC2DLineDataPointSymbolProperty,
  SFC2DLineShadowProperty,
  SFC2DLineStrokeProperty,
  SFC2DLineUseSeriesFillForDataPointFillProperty,
  SFC2DLineUseStrokeColorForDataPointFillProperty,
  SFC2DMixedAreaDataPointFillProperty,
  SFC2DMixedAreaDataPointStrokeProperty,
  SFC2DMixedAreaDataPointSymbolProperty,
  SFC2DMixedAreaFillProperty,
  SFC2DMixedAreaShadowProperty,
  SFC2DMixedAreaStrokeProperty,
  SFC2DMixedAreaUseSeriesFillForDataPointFillProperty,
  SFC2DMixedAreaUseStrokeColorForDataPointFillProperty,
  SFC2DMixedColumnFillProperty,
  SFC2DMixedColumnShadowProperty,
  SFC2DMixedColumnStrokeProperty,
  SFC2DMixedConnectedPointsProperty,
  SFC2DMixedLineDataPointFillProperty,
  SFC2DMixedLineDataPointStrokeProperty,
  SFC2DMixedLineDataPointSymbolProperty,
  SFC2DMixedLineShadowProperty,
  SFC2DMixedLineStrokeProperty,
  SFC2DMixedLineUseStrokeColorForDataPointFillProperty,
  SFC2DOpacityProperty,
  SFC2DPieFillProperty,
  SFC2DPieShadowProperty,
  SFC2DPieStrokeProperty,
  SFC2DRightBorderOpacityProperty,
  SFC2DRightBorderShadowProperty,
  SFC2DRightBorderStrokeProperty,
  SFC2DScatterDataPointFillProperty,
  SFC2DScatterDataPointStrokeProperty,
  SFC2DScatterDataPointSymbolProperty,
  SFC2DScatterDataPointSymbolSizeProperty,
  SFC2DScatterShadowProperty,
  SFC2DScatterStrokeProperty,
  SFC2DShowBottomBorderProperty,
  SFC2DShowBottomTicksProperty,
  SFC2DShowCategoryDirectionGridLinesProperty,
  SFC2DShowCategoryDirectionMinorGridLinesProperty,
  SFC2DShowLeftBorderProperty,
  SFC2DShowLeftTicksProperty,
  SFC2DShowRightBorderProperty,
  SFC2DShowRightTicksProperty,
  SFC2DShowTopBorderProperty,
  SFC2DShowTopTicksProperty,
  SFC2DShowValueDirectionGridLinesProperty,
  SFC2DShowValueDirectionMinorGridLinesProperty,
  SFC2DTopBorderOpacityProperty,
  SFC2DTopBorderShadowProperty,
  SFC2DTopBorderStrokeProperty,
  SFC2DValueDirectionGridLineOpacityProperty,
  SFC2DValueDirectionGridLineShadowProperty,
  SFC2DValueDirectionGridLineStrokeProperty,
  SFC2DValueDirectionMinorGridLineIntervalProperty,
  SFC2DValueDirectionMinorGridLineOpacityProperty,
  SFC2DValueDirectionMinorGridLineShadowProperty,
  SFC2DValueDirectionMinorGridLineStrokeProperty,
  SFC3DAreaChartScaleProperty,
  SFC3DAreaFillProperty,
  SFC3DAreaLightingPackageProperty,
  SFC3DAreaShadowProperty,
  SFC3DBarChartScaleProperty,
  SFC3DBarFillProperty,
  SFC3DBarLightingPackageProperty,
  SFC3DBarShadowProperty,
  SFC3DBarShapeProperty,
  SFC3DBevelEdgesProperty,
  SFC3DCameraTypeProperty,
  SFC3DCategoryDirectionGridLineOpacityProperty,
  SFC3DCategoryDirectionGridLineStrokeProperty,
  SFC3DChartRotationProperty,
  SFC3DChartScaleProperty,
  SFC3DColumnBevelEdgesProperty,
  SFC3DColumnChartScaleProperty,
  SFC3DColumnFillProperty,
  SFC3DColumnLightingPackageProperty,
  SFC3DFloorDepthProperty,
  SFC3DFloorEmissiveColorProperty,
  SFC3DFloorFillProperty,
  SFC3DFloorSpecularColorProperty,
  SFC3DInterSetDepthGapProperty,
  SFC3DLabelThicknessProperty,
  SFC3DLightingPackageProperty,
  SFC3DLineChartScaleProperty,
  SFC3DLineFillProperty,
  SFC3DLineLightingPackageProperty,
  SFC3DLineShadowProperty,
  SFC3DMaterialPackageProperty,
  SFC3DPieBevelEdgesProperty,
  SFC3DPieChartScaleProperty,
  SFC3DPieFillProperty,
  SFC3DPieLightingPackageProperty,
  SFC3DPieShadowProperty,
  SFC3DReflectionsLevelProperty,
  SFC3DSceneBackgroundColorProperty,
  SFC3DSceneShowTextureProperty,
  SFC3DSceneTextureTilingProperty,
  SFC3DSeriesEmissiveColorProperty,
  SFC3DSeriesShininessProperty,
  SFC3DSeriesSpecularColorProperty,
  SFC3DShadowCameraXProperty,
  SFC3DShadowCameraYProperty,
  SFC3DShadowProperty,
  SFC3DShowBackWallProperty,
  SFC3DShowFloorProperty,
  SFC3DShowReflectionsProperty,
  SFC3DTextureProperty,
  SFC3DTextureTilingProperty,
  SFC3DValueDirectionGridLineOpacityProperty,
  SFC3DValueDirectionGridLineStrokeProperty,
  SFC3DWallEmissiveColorProperty,
  SFC3DWallFillProperty,
  SFC3DWallSpecularColorProperty,
  SFC3DWallsShininessProperty,
  SFCAreaSeriesValueParagraphStyleProperty,
  SFCAreaShowValueLabelProperty,
  SFCAreaValueLabelPositionProperty,
  SFCAxisLabelsOrientationProperty,
  SFCBarSeriesValueParagraphStyleProperty,
  SFCBarShowValueLabelProperty,
  SFCBarValueLabelPositionProperty,
  SFCCategoryAxisLabelsDepthProperty,
  SFCCategoryAxisLabelsOpacityProperty,
  SFCCategoryAxisLabelsOrientationProperty,
  SFCCategoryAxisLabelsPositionProperty,
  SFCCategoryAxisMajorTickLengthProperty,
  SFCCategoryAxisMajorTickStrokeProperty,
  SFCCategoryAxisMinorTickLengthProperty,
  SFCCategoryAxisMinorTickStrokeProperty,
  SFCCategoryAxisParagraphStyleProperty,
  SFCCategoryAxisShowMajorTickMarksProperty,
  SFCCategoryAxisShowMinorTickMarksProperty,
  SFCCategoryAxisTickMarkLocationProperty,
  SFCCategoryAxisTitleParagraphStyleProperty,
  SFCCategoryAxisTitlePositionProperty,
  SFCCategoryHorizontalSpacingProperty,
  SFCCategoryVerticalSpacingProperty,
  SFCChartTitleParagraphStyleProperty,
  SFCChartTitlePositionProperty,
  SFCDefaultChartAngleProperty,
  SFCDefaultChartBoundsProperty,
  SFCDefaultLegendAngleProperty,
  SFCDefaultLegendBoundsProperty,
  SFCDepthProperty,
  SFCEmissiveColorProperty,
  SFCErrorBarXAxisStrokeProperty,
  SFCErrorBarXLineEndProperty,
  SFCErrorBarYAxisShadowProperty,
  SFCErrorBarYAxisStrokeProperty,
  SFCErrorBarYLineEndProperty,
  SFCHorizontalAxisLogarithmicProperty,
  SFCHorizontalAxisNumberFormatSeparatorProperty,
  SFCHorizontalAxisNumberOfDecadesProperty,
  SFCHorizontalAxisNumberOfStepsProperty,
  SFCHorizontalAxisShowMinimumValueProperty,
  SFCInitialNumberOfSeriesProperty,
  SFCInterBarGapProperty,
  SFCInterSetGapProperty,
  SFCLabelOpacityProperty,
  SFCLabelShadowProperty,
  SFCLegendFillProperty,
  SFCLegendOpacityProperty,
  SFCLegendParagraphStyleProperty,
  SFCLegendPositionProperty,
  SFCLegendShadowProperty,
  SFCLegendStrokeProperty,
  SFCLineSeriesValueParagraphStyleProperty,
  SFCLineShowValueLabelProperty,
  SFCLineValueLabelPositionProperty,
  SFCMixedAreaValueLabelPositionProperty,
  SFCMixedColumnValueLabelPositionProperty,
  SFCMixedLineValueLabelPositionProperty,
  SFCMixedSeriesValueParagraphStyleProperty,
  SFCMixedShowValueLabelProperty,
  SFCNumberOfDefinedSeriesStylesProperty,
  SFCPieSeriesStartAngleProperty,
  SFCPieSeriesValueParagraphStyleProperty,
  SFCPieShowSeriesNameLabelProperty,
  SFCPieShowValueLabelProperty,
  SFCPieValueLabelPosition2Property,
  SFCPieValueLabelPositionProperty,
  SFCPieWedgeExplosionProperty,
  SFCPieWedgeGroupingsProperty,
  SFCSeriesValueLabelDateTimeFormatProperty,
  SFCSeriesValueLabelDurationFormatProperty,
  SFCSeriesValueLabelFormatTypeProperty,
  SFCSeriesValueLabelNumberFormatProperty,
  SFCSeriesValueLabelPercentageAxisNumberFormatProperty,
  SFCSeriesValueLabelPieFormatTypeProperty,
  SFCSeriesValueLabelPieNumberFormatProperty,
  SFCShininessProperty,
  SFCShowCategoryAxisLabelsProperty,
  SFCShowCategoryAxisSeriesLabelsProperty,
  SFCShowCategoryAxisTitleProperty,
  SFCShowChartTitleProperty,
  SFCShowLastCategoryAxisLabelsProperty,
  SFCShowPieLabelAsPercentageProperty,
  SFCShowValueAxisTitleProperty,
  SFCShowValueY2AxisTitleProperty,
  SFCSpecularColorProperty,
  SFCStackedAreaValueLabelPositionProperty,
  SFCStackedBarValueLabelPositionProperty,
  SFCTrendlineEquationOpacityProperty,
  SFCTrendlineEquationParagraphStyleProperty,
  SFCTrendlineRSquaredOpacityProperty,
  SFCTrendlineRSquaredParagraphStyleProperty,
  SFCTrendLineShadowProperty,
  SFCTrendLineStrokeProperty,
  SFCValueAxisDateTimeFormatProperty,
  SFCValueAxisDurationFormatProperty,
  SFCValueAxisFormatTypeProperty,
  SFCValueAxisHorizontalDateTimeFormatProperty,
  SFCValueAxisHorizontalDurationFormatProperty,
  SFCValueAxisHorizontalFormatTypeProperty,
  SFCValueAxisHorizontalNumberFormatProperty,
  SFCValueAxisLabelsDepthProperty,
  SFCValueAxisLabelsOpacityProperty,
  SFCValueAxisLabelsOrientationProperty,
  SFCValueAxisLabelsPositionProperty,
  SFCValueAxisLogarithmicProperty,
  SFCValueAxisMajorTickLengthProperty,
  SFCValueAxisMajorTickStrokeProperty,
  SFCValueAxisMaximumValueProperty,
  SFCValueAxisMinimumValueProperty,
  SFCValueAxisMinorTickLengthProperty,
  SFCValueAxisMinorTickStrokeProperty,
  SFCValueAxisNumberFormatProperty,
  SFCValueAxisNumberOfDecadesProperty,
  SFCValueAxisNumberOfStepsProperty,
  SFCValueAxisParagraphStyleProperty,
  SFCValueAxisPercentageProperty,
  SFCValueAxisShowMajorTickMarksProperty,
  SFCValueAxisShowMinimumValueProperty,
  SFCValueAxisShowMinorTickMarksProperty,
  SFCValueAxisTickMarkLocationProperty,
  SFCValueAxisTitleParagraphStyleProperty,
  SFCValueAxisTitlePositionPropertya,
  SFCValueAxisY2DateTimeFormatProperty,
  SFCValueAxisY2DurationFormatProperty,
  SFCValueAxisY2FormatTypeProperty,
  SFCValueAxisY2NumberFormatProperty,
  SFCValueAxisY2ParagraphStyleProperty,
  SFCValueAxisY2TitleParagraphStyleProperty,
  SFCValueNumberFormatDecimalPlacesProperty,
  SFCValueNumberFormatPrefixProperty,
  SFCValueNumberFormatSeparatorProperty,
  SFCValueNumberFormatSuffixProperty,
  SFCValueY2AxisLabelsDepthProperty,
  SFCValueY2AxisLabelsOpacityProperty,
  SFCValueY2AxisLabelsOrientationProperty,
  SFCValueY2AxisLabelsPositionProperty,
  SFCValueY2AxisLogarithmicProperty,
  SFCValueY2AxisMajorTickLengthProperty,
  SFCValueY2AxisMajorTickStrokeProperty,
  SFCValueY2AxisMinorTickLengthProperty,
  SFCValueY2AxisMinorTickStrokeProperty,
  SFCValueY2AxisNumberOfDecadesProperty,
  SFCValueY2AxisNumberOfStepsProperty,
  SFCValueY2AxisPercentageProperty,
  SFCValueY2AxisShowMajorTickMarksProperty,
  SFCValueY2AxisShowMinimumValueProperty,
  SFCValueY2AxisShowMinorTickMarksProperty,
  SFCValueY2AxisTickMarkLocationProperty,
  SFRReflection,
  SFTableCellStylePropertyFill,
  SFTableCellStylePropertyType,
  SFTableStylePropertyBackgroundFill,
  SFTableStylePropertyBorderVectorStyle,
  SFTableStylePropertyCellLayoutStyle,
  SFTableStylePropertyCellParagraphStyle,
  SFTableStylePropertyCellStyle,
  SFTableStylePropertyHeaderBorderVectorStyle,
  SFTableStylePropertyHeaderColumnCellLayoutStyle,
  SFTableStylePropertyHeaderColumnCellParagraphStyle,
  SFTableStylePropertyHeaderColumnCellStyle,
  SFTableStylePropertyHeaderRowCellLayoutStyle,
  SFTableStylePropertyHeaderRowCellParagraphStyle,
  SFTableStylePropertyHeaderRowCellStyle,
  SFTableStylePropertyHeaderSeperatorVectorStyle,
  SFTableStylePropertyHeaderVectorStyle,
  SFTableStylePropertyPrototypeColumnCount,
  SFTableStylePropertyPrototypeGeometry,
  SFTableStylePropertyPrototypeIsHeaderColumn,
  SFTableStylePropertyPrototypeIsHeaderRow,
  SFTableStylePropertyPrototypeIsResize,
  SFTableStylePropertyPrototypeRowCount,
  SFTableStylePropertyVectorStyle,
  SFTAutoResizeProperty,
  SFTBackgroundProperty,
  SFTCellStylePropertyDateTimeFormat,
  SFTCellStylePropertyDurationFormat,
  SFTCellStylePropertyFormatType,
  SFTCellStylePropertyImplicitFormatType,
  SFTCellStylePropertyLayoutStyle,
  SFTCellStylePropertyNumberFormat,
  SFTCellStylePropertyParagraphStyle,
  SFTCellTextWrapProperty,
  SFTDefaultBodyCellStyleProperty,
  SFTDefaultBodyVectorStyleProperty,
  SFTDefaultBorderVectorStyleProperty,
  SFTDefaultColumnCountProperty,
  SFTDefaultFooterBodyVectorStyleProperty,
  SFTDefaultFooterBorderVectorStyleProperty,
  SFTDefaultFooterRowCellStyleProperty,
  SFTDefaultFooterRowCountProperty,
  SFTDefaultFooterSeparatorVectorStyleProperty,
  SFTDefaultGeometryProperty,
  SFTDefaultGroupingLevel0VectorStyleProperty,
  SFTDefaultGroupingLevel1VectorStyleProperty,
  SFTDefaultGroupingLevel2VectorStyleProperty,
  SFTDefaultGroupingLevel3VectorStyleProperty,
  SFTDefaultGroupingLevel4VectorStyleProperty,
  SFTDefaultGroupingRow0CellStyleProperty,
  SFTDefaultGroupingRow1CellStyleProperty,
  SFTDefaultGroupingRow2CellStyleProperty,
  SFTDefaultGroupingRow3CellStyleProperty,
  SFTDefaultGroupingRow4CellStyleProperty,
  SFTDefaultHeaderBodyVectorStyleProperty,
  SFTDefaultHeaderBorderVectorStyleProperty,
  SFTDefaultHeaderColumnCellStyleProperty,
  SFTDefaultHeaderColumnCountProperty,
  SFTDefaultHeaderRowCellStyleProperty,
  SFTDefaultHeaderRowCountProperty,
  SFTDefaultHeaderSeparatorVectorStyleProperty,
  SFTDefaultRowCountProperty,
  SFTDefaultTableNameIsDisplayedProperty,
  SFTGroupingRowFillProperty,
  SFTHeaderColumnRepeatsProperty,
  SFTHeaderRowRepeatsProperty,
  SFTStrokeProperty,
  SFTTableBandedCellFillProperty,
  SFTTableBandedRowsProperty,
  SFTTableBehaviorProperty,
  shadow,
  shadow_ref,
  shape,
  showInTOC,
  shrinkTextToFit,
  size,
  slide,
  slide_list,
  slide_number_placeholder,
  slide_number_placeholder_ref,
  slideNumberPlaceholderVisibility,
  slide_ref,
  slide_style,
  sort,
  sort_spec,
  soundtrack_list,
  spaceAfter,
  spaceBefore,
  span,
  sticky_notes,
  stops,
  strikethru,
  strikethruColor,
  strikethruWidth,
  string,
  stroke,
  stroke_ref,
  style,
  style_ref,
  styles,
  stylesheet,
  stylesheet_ref,
  superscript,
  tab,
  table_cell,
  tableCellArrayCellsByColumn,
  tableCellArrayCellsByRow,
  tableCellContent,
  tableCellMaxXSide_ref,
  tableCellMaxYSide_ref,
  tableCellMinXSide_ref,
  tableCellMinYSide_ref,
  table_cell_ref,
  table_cell_style,
  TableCellStylePropertyFormatDecimals,
  TableCellStylePropertyFormatEnabled,
  TableCellStylePropertyFormatNegativeStyle,
  TableCellStylePropertyFormatPrefix,
  TableCellStylePropertyFormatSuffix,
  TableCellStylePropertyFormatThousandsSeparator,
  table_cell_style_ref,
  tableCellStyle_ref,
  tableCellValue,
  table_info,
  tableInfoTable,
  tableModelCells,
  tableModelPartitionSource,
  tableModelStyle_ref,
  tableModelTableID,
  tableModelVectors,
  table_style,
  table_style_ref,
  table_vector,
  tableVectorArrayColumnVectors,
  tableVectorArrayRowVectors,
  table_vector_style,
  table_vector_style_ref,
  tableVectorStyle_ref,
  TableVectorStyleStrokeProperty,
  TableVectorStyleTypeProperty,
  tabs,
  tabs_ref,
  tabstop,
  tabular_info,
  tabular_model,
  tabular_model_ref,
  tabular_style,
  tabular_style_ref,
  tail,
  tailLineEnd,
  tailOffset,
  target_bounds,
  text,
  textBackground,
  text_body,
  textBorders,
  text_cell,
  text_label,
  text_label_ref,
  textShadow,
  text_storage,
  textured_fill,
  textured_fill_ref,
  texture_fill,
  theme,
  theme_list,
  thumbnails,
  title,
  title_placeholder,
  title_placeholder_ref,
  titlePlaceholderVisibility,
  tocStyle,
  traced_path,
  tracking,
  transition,
  transition_attributes,
  transition_attributes_ref,
  type,
  ui_state,
  underline,
  underlineColor,
  underlineWidth,
  unfiltered,
  unfiltered_ref,
  value,
  value_ref,
  vector3d,
  vector_style,
  vector_style_ref,
  version_history,
  verticalAlignment,
  vertical_gridline_styles,
  verticalText,
  widowControl,
  word_strikethrough,
  word_underline,
  wrap,

  // attributes
  a,
  align,
  all_images_bundled,
  alpha_threshold,
  amt,
  angle,
  array_size,
  aspectRatioLocked,
  asset_scale,
  attachment_wrap_type,
  auto_defers_to_parent,
  automatic,
  b,
  bottom,
  can_autosize_h,
  can_autosize_v,
  cap,
  cell_style_default_line_height,
  chart_data_modified,
  chart_direction,
  chart_perspectivemultiplier,
  chart_type,
  checksum,
  chunking,
  class_,
  col,
  collapsed,
  compatible_version,
  component,
  copyonwrite,
  corrupt,
  count,
  decimal_tab,
  delay,
  delay_archiving,
  depth,
  displayname,
  duration,
  enabled,
  equal_columns,
  excl,
  exclude_attachments,
  exclude_charts,
  exclude_shapes,
  exclude_tables,
  filled,
  filterClassName,
  filter_col,
  first,
  fitting_height,
  fitting_width,
  flags,
  floating_wrap_enabled,
  floating_wrap_type,
  fmt,
  format,
  format_currency_code,
  format_decimal_places,
  format_fraction_accuracy,
  format_negative_style,
  format_show_thousands_separator,
  format_string,
  format_type,
  format_use_accounting_style,
  fraction,
  g,
  grouping_enabled,
  group_uuid,
  h,
  hash,
  height,
  hfs_type,
  hiddennumcols,
  hiddennumrows,
  horizontalFlip,
  href,
  id,
  ID,
  ident,
  identifier,
  IDREF,
  index,
  inflection,
  inheritance,
  is_null,
  join,
  key1,
  keyscale,
  kind,
  kiosk_build_delay,
  kiosk_slide_delay,
  label_pos,
  left,
  length,
  locked,
  looping,
  manually_sized,
  margin,
  miter_limit,
  mode,
  muted,
  name,
  name_is_visible,
  non_empty,
  numcols,
  num_footer_rows,
  num_header_columns,
  num_header_rows,
  numrows,
  ocnt,
  offset,
  orientation,
  orientation_ignored,
  override_autosize,
  override_geometry_mask,
  override_media,
  override_text,
  parent_ident,
  partitionSourceBodyFrame,
  partitionSourceBottomMarginExtendsIn,
  partitionSourceBottomMarginExtendsOut,
  partitionSourceBottomMarginFrame,
  partitionSourceBounds,
  partitionSourceLeftMarginFrame,
  partitionSourceRightMarginFrame,
  partitionSourceShinkToFitWidth,
  partitionSourceTopMarginExtendsIn,
  partitionSourceTopMarginExtendsOut,
  partitionSourceTopMarginFrame,
  phase,
  placeholder,
  play_mode,
  pos,
  poster,
  predicate,
  preferred_height,
  preferred_width,
  r,
  radius,
  referent,
  referent_defers_to_parent,
  resource_type,
  right,
  row,
  scalar,
  scale,
  scale_with_text,
  seriesIndex,
  sfclass,
  sharable,
  shearXAngle,
  shearYAngle,
  sizesLocked,
  sort_col,
  sort_order,
  spacing,
  spec_count,
  sticky_visibility,
  tableCellPreferredHeight,
  tableIsForPasteboardOnly,
  tableModelIsHeaderColumn,
  tableModelIsHeaderRow,
  tableModelResize,
  tableVectorAlong,
  tableVectorAxis,
  tableVectorBegin,
  tableVectorEnd,
  tabuar_style_name_internal,
  tabular_style_name_internal,
  tag,
  technique,
  text_pos,
  top,
  traced_threshold,
  tscale,
  val,
  version,
  verticalFlip,
  volume,
  w,
  width,
  wrap_style,
  x,
  y,
  z,

  // attribute values
  COMPATIBLE_VERSION_STR_3,
  VERSION_STR_2,
  VERSION_STR_3,
  VERSION_STR_4,
  VERSION_STR_5,
  _0,
  _1,
  false_,
  true_,

  LAST_TOKEN = true_
};

}

const KNToken *getKN2Token(const char *str, const unsigned length);
const KNToken *getKN2Token(const char *str);
const KNToken *getKN2Token(const unsigned char *str);

int getKN2TokenID(const KNToken &token);
int getKN2TokenID(const KNToken *token);
int getKN2TokenID(const char *str, const unsigned length);
int getKN2TokenID(const char *str);
int getKN2TokenID(const unsigned char *str);

const char *getKN2TokenName(const KNToken &token);
const char *getKN2TokenName(const KNToken *token);
const char *getKN2TokenName(const char *str, const unsigned length);
const char *getKN2TokenName(const char *str);
const char *getKN2TokenName(const unsigned char *str);

}

#endif // KN2TOKEN_H_INCLUDED

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
